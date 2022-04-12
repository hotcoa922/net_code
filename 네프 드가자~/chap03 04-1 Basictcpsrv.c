//���ص� - 90%
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#define PORT 9001

int main()
{
	int srvSd, clntSd;	//����, Ŭ���̾�Ʈ ���� ���ϵ�ũ����
	struct sockaddr_in srvAddr, clntAddr;	//����, Ŭ���̾�Ʈ �ּҿ� ����ü
	int clntAddrLen, readLen;	//Ŭ���̾�Ʈ �ּ� ����, ���� �� ����
	char rBuff[BUFSIZ];	//���� receive���� ũ��(������)
	char wBuff[] = "I am 20 years old.";	//������ Ŭ���̾�Ʈ���� ������ ��, �̸� ������(���ǻ�)


	srvSd = socket(AF_INET, SOCK_STREAM, 0);	//���� ���� ���� (IPv4, SOCK_STREAM(TCP), 0�� TCP��������)
	if (srvSd == -1)
	{
		printf("Socket Error\n");
		return -1;
	}

	//���� �ּҰ��� ����ü ����
	memset(&srvAddr, 0, sizeof(srvAddr));
	srvAddr.sin_family = AF_INET; //IPv4
	srvAddr.sin_addr.s_addr = htonl(INADDR_ANY);	//ȣ��Ʈ ����Ʈ���Ŀ��� ��Ʈ��ũ ����Ʈ����(�򿡵��)
	srvAddr.sin_port = htons(PORT); //���� ����

	//���ε�
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


	//���� �� read, write�Լ��� ���� ���� receive, send�Լ��� �ٲپ �ȴ�.
	return 0;
}