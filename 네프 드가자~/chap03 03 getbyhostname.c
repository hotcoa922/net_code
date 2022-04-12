// 이해도 - 80%
#include <stdio.h>
#include <netdb.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

//테스트 코드  : ./getbyhostname.c www.naver.com
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

	ent = gethostbyname(argv[1]);	//ent 포인터에 www.naver.com 저장
	if (ent == NULL) errProc("gethostbyname");

	res = (struct in_addr**)ent->h_addr_list;	//이건 잘 모르겠음, 아마 여러개인듯
	printf("hostname: %s \n", ent->h_name);		//www.naver.com 출력
	while (res[i] != NULL)
	{
		printf("%s ", inet_ntoa(*res[i]));	//가능한 ip주소 모두 출력, inet_ntoa이므로 10진수. 형태 로 출력
		i++;
	}
	printf("\n");

}

void errProc(const char* str)
{
	fprintf(stderr, "%s: %s\n", str, strerror(errno));
	exit(errno);
}
