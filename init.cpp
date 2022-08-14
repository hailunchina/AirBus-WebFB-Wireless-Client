# include "WebFB.hpp"

/* IMPORTANT FILES:
    - BTI429.h
    - BTICard.h
    - libbti429.so
    - libbtiCard.so
    - global.h
    - WebFB.h
*/

//! MAIN IS ONLY USED FOR ME TO ENSURE EVERYTHING COMPILES; DO NOT INCLUDE IN APP
int main() {
    WebFB testObj(DEFAULT_IP, DEFAULT_PORT);
    return 0;
}