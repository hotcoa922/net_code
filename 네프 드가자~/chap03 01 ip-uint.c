// ���ص� - 100%
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>

//�׽�Ʈ ��� : ./ip-uint
int main(int argc, char** argv) {
    uint32_t ipInInt;
    char* ipInStr = "127.0.0.1";        // loopback�ּ�
    ipInInt = inet_network(ipInStr);    // host����Ʈ����

    printf("String: %s, Deciaml: %u, Hex: %X \n", ipInStr, ipInInt, ipInInt);   //deciaml�� 10���� hex�� 16����

    ipInInt = htonl(ipInInt);           // network����Ʈ ����
    printf("After htonl - Decimal: %u, Hex: %X \n", ipInInt, ipInInt);

    return 0;
}

// inet_network() + htonl -> inet_addr()