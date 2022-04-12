//이해도 - 90%
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#define PORT 9001

int main()
{
	int srvSd, clntSd;	//서버, 클라이언트 소켓 파일디스크립터
	struct sockaddr_in srvAddr, clntAddr;	//서버, 클라이언트 주소용 구조체
	int clntAddrLen, readLen;	//클라이언트 주소 길이, 읽을 값 길이
	char rBuff[BUFSIZ];	//실제 receive버퍼 크기(정해짐)
	char wBuff[] = "I am 20 years old.";	//서버가 클라이언트에게 보내는 값, 미리 정해줌(편의상)


	srvSd = socket(AF_INET, SOCK_STREAM, 0);	//서버 소켓 만듬 (IPv4, SOCK_STREAM(TCP), 0은 TCP프로토콜)
	if (srvSd == -1)
	{
		printf("Socket Error\n");
		return -1;
	}

	//소켓 주소관련 구조체 세팅
	memset(&srvAddr, 0, sizeof(srvAddr));
	srvAddr.sin_family = AF_INET; //IPv4
	srvAddr.sin_addr.s_addr = htonl(INADDR_ANY);	//호스트 바이트정렬에서 네트워크 바이트정렬(빅에디안)
	srvAddr.sin_port = htons(PORT); //위와 동일

	//바인딩
	if (bind(srvSd, (struct sockaddr*)&srvAddr, sizeof(srvAddr)) == -1)
	{
		printf("Bind Error");
		return -1;
	}

	//listen
	if (listen(srvSd, 5) == -1)
	{
		printf("Listen Error");
		return -1;
	}

	//client accept
	clntAddrLen = sizeof(clntAddr);
	clntSd = accept(srvSd, (struct sockaddr*)&clntAddr, &clntAddrLen);
	if (clntSd == -1)
	{
		printf("Accept Error");
		return -1;
	}

	readLen = read(clntSd, rBuff, sizeof(rBuff) - 1);
	if (readLen == -1)
	{
		printf("Read Error");
		return -1;
	}
	rBuff[readLen] = '\0';
	printf("Client: %s \n", rBuff);


	write(clntSd, wBuff, sizeof(wBuff));
	close(clntSd);
	close(srvSd);


	//위에 쓴 read, write함수는 각각 각각 receive, send함수로 바꾸어도 된다.
	return 0;
}