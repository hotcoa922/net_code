// 이해도 - 100%
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>

//테스트 명령 : ./ip-uint
int main(int argc, char** argv) {
    uint32_t ipInInt;
    char* ipInStr = "127.0.0.1";        // loopback주소
    ipInInt = inet_network(ipInStr);    // host바이트정렬

    printf("String: %s, Deciaml: %u, Hex: %X \n", ipInStr, ipInInt, ipInInt);   //deciaml은 10진수 hex는 16진수

    ipInInt = htonl(ipInInt);           // network바이트 정렬
    printf("After htonl - Decimal: %u, Hex: %X \n", ipInInt, ipInInt);

    return 0;
}

// inet_network() + htonl -> inet_addr()