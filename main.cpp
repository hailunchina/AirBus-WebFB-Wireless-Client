#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "btiutil.h"
#include "btisocket.h"

#include "global.h"

#define C "\033[1;36m"	// Cyan
#define R "\033[1;31m" 	// Red
#define G "\033[1;32m" 	// Green
#define M "\033[1;35m"	// Magenta 
#define RST "\033[0m" 	// Reset

void init_console(struct termios *oldattr);
void restore_console(struct termios oldattr);
int getch(void);
int ParsePackets(LPUINT16 buf, uint32_t wordcount);

int main(int argc, char *argv[]) {
	int ch;
	UINT16 buf[MAXPACKETSIZE];
	int result;
	struct termios oldattr;

	//	Create a socket
	printf("\n%s[STATUS]: CREATING SOCKET%s\n", M, RST);

	if (!SocketCreate()) {
		printf("%s[ERROR]: Unable to create socket... Exiting (errno=%d)%s", R, errno, RST);
		exit(1);

	} else {
		printf("\n%s[SUCCESS]: SOCKET CREATED%s\n", G, RST);

	}

	//	Connect to BTIAIDSvc socket
	printf("\n%s[STATUS]: ATTEMPTING TO CONNECT%s\n", M, RST);

	if (!SocketConnect()) {
		printf("%s[ERROR]: Unable to connect to socket... Exiting%s\n", R, RST);
		exit(1);

	} else {
		printf("\n%s[SUCCESS]: CONNECTION ESTABLISHED%s\n", G, RST);

	}


	//	Setup the socket signal polling
	printf("\n%s[STATUS]: INITIALIZING SIGNAL POLLING%s\n", M, RST);
	if (!SocketSetupPoll()) {
		printf("%s[ERROR]: Unable to setup signal poll... Exiting (errno=%d)%s", R, errno, RST);
		exit(1);

	} else {
		printf("\n%s[SUCCESS]: SIGNAL POLL ACTIVE%s\n", G, RST);

	}

	init_console(&oldattr); //	Clear the console screen and set position 0,0
	printf("\n%s[STATUS]: ENTERING MAIN LOOP%s\n", M, RST);

	//	Start the main loop
	while (1) {
		switch (SocketPoll()) {
			default: printf("\n%s[ERROR]: SocketPoll (errno=%d)%s\n", R, errno, RST); break;
			case 0: break; //Timeout
			case 2: break; // No Data
			case 1: //Data Ready
				result = SocketDataRd(buf, MAXPACKETSIZE);
				if (result < 0) {
					printf("SocketDataRd returned %i",result);
				} else if (result > 0) {
					ParsePackets(buf, result); /* Do Something w/ data */
				}
				break;
		}
	}

	printf("\n\n");
	restore_console(oldattr);
	return 0;
}


//	Parse data packets read from the socket
int ParsePackets(LPUINT16 buf, uint32_t wordcount)
{
	ERRVAL           errval;
	SEQFINDINFO      sfinfo;
	UINT16           seqtype;
	LPUINT16         pRec;

	LPSEQRECORD717SF pRec717;
	LPSEQRECORD429   pRec429;

	std::stringstream ss;
	std::string hexStr("");
	std::string bit1428Str("");
	std::string laloStr("");
	bool valid(true);
	std::string LAT("c8"), LON("c9");
	std::string w32("");
	LaLo LatLon;
	Parity par29, par32;
	double dec(0);

	errval = BTICard_SeqFindInit(buf, wordcount, &sfinfo);

	if (errval) {
		syslog(LOG_ERR,"ParsePackets - SeqFindInit Failed (%i)", errval);
		return -1;
	}

	//	Walk the record stream using our modified find-next method
	while(!BTIUTIL_SeqFindNext(&pRec,&seqtype,&sfinfo)) {
		switch(seqtype) {
			default: break;
			case SEQTYPE_429:	
				pRec429 = (LPSEQRECORD429)pRec;

				w32 = "";
				hexStr = "";
				ss.clear();
	
				// Grab data (HEX)
				ss << std::hex << ntohl(pRec429->data);
				hexStr = ss.str();

				if (hexStr.size() == 8) {
					//! Check if lat or lon
					laloStr = hexStr.substr(hexStr.length()-2);
					if(laloStr == LAT) {
						LatLon = (LaLo)0;
					} else if (laloStr == LON) {
						LatLon = (LaLo)1;
					} else {
						valid = false;
					}
				
					if (valid) {
						printf("%sHEX: 0x%s %s\n", C, hexStr.c_str(), RST);

						//! Convert hex to 32-bit word
						for (auto& i : hexStr) { w32 += hexMap.at(i); }
						printf("%s32-BIT WORD: %s %s\n", C, w32.c_str(), RST);

						//! grab bits 14-28
						bit1428Str = w32.substr(4, 20); 
						printf("%sBITS 14-28: %s %s\n", C, bit1428Str.c_str(), RST);

						//! Convert 14-28 to decimal & multiply
						dec = std::stol(bit1428Str.c_str(), nullptr, 2)*0.00017166154;
						printf("%sBITS 14-28 [DECIMAL]: %.6f %s \n", C, dec, RST);

						//! Check for Parity
						//? Change based on order
						par29 = (Parity)(w32.at(3) - '0'); //* ASCII magic
						par32 = (Parity)(w32.at(0) - '0');

					}
				}
		}
	}

	return 0;
}

//	Save console settings in oldattr and setup console with new settings
void init_console(struct termios *oldattr) {
	struct termios newattr;

	tcgetattr(0,oldattr);
	newattr = *oldattr;
	newattr.c_lflag &= ~ICANON;
	newattr.c_lflag &= ~ISIG;
	newattr.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL);
	newattr.c_cc[VMIN] = 0;
	newattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);

	printf("\033[2J");    //clear screen
	printf("\033[0;0H");  //set position to 0,0
}

//	Restore console setting contained in oldattr
void restore_console(struct termios oldattr) {
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr);
}

//	Reads from key-press, doesn't echo
int getch(void) {
	int ch;
	ch = getchar();
	return ch;
}

