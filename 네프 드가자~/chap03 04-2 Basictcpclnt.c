//이해도 - 90%
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#define PORT 9001

int main()
{
	int clntSd;
	struct sockaddr_in clntAddr;
	int clntAddrLen, readLen;
	char wBuff[] = "How old are you?";	//쓰기 버퍼
	char rBuff[BUFSIZ];	//읽기 버퍼



	clntSd = socket(PF_INET, SOCK_STREAM, 0);	//클라이언트 소켓 만듬 (IPv4, SOCK_STREAM(TCP), 0은 TCP프로토콜)
	if (clntSd == -1)
	{
		printf("Socket Creation Error");
		return -1;
	}
	clntAddr.sin_family = AF_INET;
	clntAddr.sin_addr.s_addr = inet_addr("127.0.0.1");	//문자열 형태의 IPv4주소를 네트워크바이트정렬(빅에디안)의 32비트 숫자로 변환
	clntAddr.sin_port = htons(PORT);

	if (connect(clntSd, (struct sockaddr*)&clntAddr, sizeof(clntAddr)) == -1)


	{
		printf("Connect Error");
		close(clntSd);
		return -1;
	}



	write(clntSd, wBuff, sizeof(wBuff));
	printf("Client: %s\n", wBuff);

	readLen = read(clntSd, rBuff, sizeof(rBuff) - 1);
	if (readLen == -1)
	{
		printf("Read Error");
		return -1;
	}
	rBuff[readLen] = '\0';
	printf("Server: %s\n", rBuff);
	close(clntSd);
	return 0;
}