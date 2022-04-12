// ���ص� - 80%
#include <stdio.h>
#include <netdb.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

//�׽�Ʈ �ڵ�  : ./getbyhostname.c www.naver.com
void errProc(const char*);
int main(int argc, char** argv)
{
	struct hostent* ent;
	struct in_addr** res;
	int i = 0;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <hostname> \n", argv[0]);
		return -1;
	}

	ent = gethostbyname(argv[1]);	//ent �����Ϳ� www.naver.com ����
	if (ent == NULL) errProc("gethostbyname");

	res = (struct in_addr**)ent->h_addr_list;	//�̰� �� �𸣰���, �Ƹ� �������ε�
	printf("hostname: %s \n", ent->h_name);		//www.naver.com ���
	while (res[i] != NULL)
	{
		printf("%s ", inet_ntoa(*res[i]));	//������ ip�ּ� ��� ���, inet_ntoa�̹Ƿ� 10����. ���� �� ���
		i++;
	}
	printf("\n");

}

void errProc(const char* str)
{
	fprintf(stderr, "%s: %s\n", str, strerror(errno));
	exit(errno);
}
