#ifndef WEBFB_H
#define WEBFB_H

#include "global.hpp"

class WebFB {
public:
    manage_t data;

private:
    sigset_t    	sockSigMask;
    std::size_t		sockFD;
    std::string    	sockIP;
	std::uint16_t  	sockPort;
    std::uint32_t	sockPKT;
    std::uint32_t	sockError;

public:
    WebFB();
    WebFB(std::string IP, std::string Port);
    ~WebFB();

    int mkSock();
    int sockConnect();
    int rdSockData(std::uint16_t *pbuf, std::uint32_t bufsize);
    int initSockPoll();
    int sockPoll();
    std::string ParsePKTS(LPUINT16 buf, std::uint32_t wordcount, std::string lbl);
	std::string GetArincData(std::string lbl);
	latitude_t GetLatData();
};

//* Default Constructor
WebFB::WebFB() 
    : sockIP(DEFAULT_IP) , sockPort(stous(DEFAULT_PORT)), sockFD(-1), sockPKT(0), sockError(0) {
}

//* Paramaterized Constructor
// @param IP: IP Address
// @param Port: IP Address Port
WebFB::WebFB(std::string IP, std::string Port) 
    : sockIP(IP), sockPort(stous(Port)), sockFD(-1), sockPKT(0), sockError(0) {

    STAT("CREATING SOCKET");
	if (!this->mkSock()) { 
        FAIL("FAILED TO CREATE SOCKET...EXITING");
	} else {
		PASS("SOCKET CREATED");
	}

    STAT("ATTEMPTING TO CONNECT");
	if (!this->sockConnect()) { 
        FAIL("FAILED TO CONNECT...EXITING");
	} else {
		PASS("CONNECTION ESTABLISHED");
	}
    
    STAT("INITIALIZING SIGNAL POLLING");
	if (!this->initSockPoll()) { 
        FAIL("SIGNAL POLL SETUP FAILED...EXITING");
	} else {
		PASS("SIGNAL POLL READY");
	}

    init_console(&this->data.oldattr);
}

//* Destructor
//? Closes Socket
WebFB::~WebFB() { 
	close(this->sockFD); 
	printf("\n\n");
	restore_console(this->data.oldattr);
}

//* Creates Socket
//? Returns 0 when failure
int WebFB::mkSock() {
	this->sockFD = socket(AF_INET,SOCK_STREAM,0);
	return (int)!(this->sockFD == -1);
}

//* Connects to WebFB
//Returns 0 when failure
int WebFB::sockConnect() {
	struct sockaddr_in addr;
	int result(0);

	if (this->sockFD == -1) { return 0; }

	std::memset(&addr, 0, sizeof(addr));
    //bzero(&addr, sizeof(addr));

	addr.sin_family      = AF_INET;
	addr.sin_port        = htons(this->sockPort);
	addr.sin_addr.s_addr = inet_addr((this->sockIP.c_str()));

	result = connect(this->sockFD, (struct sockaddr*)&addr, sizeof(addr));
	if (result < 0) { return 0; }

	return 1;
}

//* Reads Data From Socket
//?  -1 = Error
//?  0 = Pulse Packet
//?  >0 = Data Packet
//   @param pbuf: Data Buffer
//   @param bufsize: Size of Buffer in Bytes
int WebFB::rdSockData(std::uint16_t *pbuf, std::uint32_t bufsize) {
	int result(0), j(0);
	std::uint32_t wordcount(0);

	if (!pbuf) { return -1; } //? Error

	result = recv(this->sockFD, (char*)&wordcount, sizeof(wordcount), MSG_WAITALL);

	//Socket error - disconnected?
	if (result <= 0) {
		//? syslog(LOG_ERR,"WebFB::rdSockData - Socket read failed (Socket error: %i)", errno);
		return -1; //? Error
	}

	//Unexpected packet
	if (result != sizeof(wordcount)) {
		//? syslog(LOG_ERR,"WebFB::rdSockData - Unexpected Packet Size (bytes) exp %li, act %i", sizeof(wordcount), result);
		return -1; //? Error
	}

	//Switch count from network to host order
	wordcount = ntohl(wordcount);

	//? Pulse packet
	if (!wordcount) { return 0; }

	//? Error: Unexpected packet
	if (wordcount > bufsize) {
		//? syslog(LOG_ERR,"WebFB::rdSockData - Unexpected Packet Size (bytes) %i, exp <= %i", wordcount * 2, bufsize);
		return -1; 
	}

	result = recv(this->sockFD, (char*)pbuf, wordcount * 2, MSG_WAITALL);

	//? Error: Socket disconnected?
	if (result <= 0) {
		//? syslog(LOG_ERR,"WebFB::rdSockData - Socket read failed (Socket error: %i)", errno);
		return -1; 
	}

	//? Error: Unexpected packet
	if (result != (wordcount * 2)) {
		//? syslog(LOG_ERR,"WebFB::rdSockData - Unexpected Packet Size (bytes) exp %i, act %i", wordcount * 2, result);
		return -1;
	} 

	this->sockPKT++;

	return wordcount;
}

//* Setup sig mask for ppoll
//? Returns 0 when failure
int WebFB::initSockPoll() {
	return !(sigprocmask(SIG_BLOCK, NULL, &(this->sockSigMask)) < 0);
}

//* Poll for events (data ready on socket)
//?	-1 = Error
//?   0 = Poll Timeout
//?   1 = Data Waiting
//?   2 = No Data
int WebFB::sockPoll() {
	nfds_t nfds(0);
	int result(0), j(0);
	struct pollfd fds[2];
	struct timespec timeout;

	timeout.tv_sec = TIMEOUT;
    timeout.tv_nsec = 0;

    std::memset(&fds, 0, sizeof(fds));

	fds[0].fd = this->sockFD;
	fds[0].events = POLLIN;
	nfds++;

	//	Poll for signal
	result = ppoll(fds, nfds, &timeout, &(this->sockSigMask));
	if (result > 0) {
		for (j = 0; j < nfds; j++) {
			if (fds[j].revents & POLLIN) {
				if (fds[j].fd == this->sockFD) { //? Data was sent from server
					return 1; //? Data Waiting
				}
			}
		}
		return 2;	//? No Data
	} else if (!result) {
		return 0; //? Poll Timeout
	}
	else if (errno == EINTR) {
		return 2; //? No Data
	}
	return -1; //? Error
}

//	Parse data packets read from the socket
//? Returns empty string on failure
std::string WebFB::ParsePKTS(LPUINT16 buf, uint32_t wordcount, std::string lbl) {
	UINT16            seqtype;
	LPUINT16          pRec;
	std::string       hexStr;
	SEQFINDINFO       sfinfo;
	LPSEQRECORD429    pRec429;
	std::stringstream ss;

	if (BTICard_SeqFindInit(buf, wordcount, &sfinfo)) {
		//? syslog(LOG_ERR,"ParsePackets - SeqFindInit Failed (%i)", errval);
		return "";
	}

	//	Walk the record stream using our modified find-next method
	//	printf("%sHEX: 0x%s %s\n", C, hexStr.c_str(), RST);
	while(!BTIUTIL_SeqFindNext(&pRec, &seqtype, &sfinfo)) {
		if (seqtype == SEQTYPE_429) {
				pRec429 = (LPSEQRECORD429)pRec;
				hexStr.clear();
				ss.clear();
	
				ss << std::hex << ntohl(pRec429->data);
				hexStr = ss.str();

				if (hexStr.size() == 8 && hexStr.substr(hexStr.length()-2) == lbl) {
					return hexStr;
				}
		}
	}
	return "";
}

// Returns raw hex given a lbl to find
std::string WebFB::GetArincData(std::string lbl) {
	std::string hexLbl(btoh(otob(lbl)));
	int result(0);

	for(;;) {
		if (this->sockPoll() == 1) { 
			result = this->rdSockData(this->data.buf, MAXPKT);
            if (result > 0) {
				return this->ParsePKTS(this->data.buf, result, hexLbl); 
			}
		}
	}
}

// Returns double corresponding to c8, latitude values translated
latitude_t WebFB::GetLatData() {
	int 		result(0);
	std::string rawHex, w32, bit1428Str;

	for(;;) {
		if (this->sockPoll() == 1) { 
			result = this->rdSockData(this->data.buf, MAXPKT);
            if (result > 0) {
				rawHex = this->ParsePKTS(this->data.buf, result, std::string("c8")); 
				for (auto& i : rawHex) { w32 += hexMap.at(std::to_string(i)); }
				bit1428Str = w32.substr(4, 20); 
				return std::stol(bit1428Str.c_str(), nullptr, 2)*0.00017166154;
			}
		}
	}
}


#endif