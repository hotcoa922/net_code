//이해도 - 90%

#include <sys/socket.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    int sD1, fD1, sD2, fD2; //파일 4개 만든 것

    sD1 = socket(PF_INET, SOCK_STREAM, 0);      // IPv4, TCP 소켓, TCP 프로토콜 소켓만들기
    fD1 = open("test1", O_RDONLY | O_CREAT);    //파일만들기
    sD2 = socket(PF_INET, SOCK_STREAM, 0);      //소켓만들기
    fD2 = open("test2", O_RDONLY | O_CREAT);    //파일만들기 

    printf("sD1:%d, fD1:%d, sD2:%d, fD2:%d \n", sD1, fD1, sD2, fD2);

    close(sD1);
    close(fD1);
    close(sD2);
    close(fD2);

    return 0;
}


//소켓도 결국 파일형태로 관리됨
