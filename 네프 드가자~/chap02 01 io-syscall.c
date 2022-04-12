//이해도 - 95%

#include <stdio.h>
#include <fcntl.h>


//테스트 명령 : ./io-syscall test.txt (엔터) How old are you?(엔터)
int main(int argc, char** argv) {
    int fD, writeLen, readLen;
    char rBuff[BUFSIZ];     // default 8192

    // 명령 인자 오류체크 영역
    if (argc != 2) {
        fprintf(stderr, "Usage : %s [Filename] \n", argv[0]);
        return 0;
    }


    // 키보드(fD:0)로부터 BUFSIZ-1 bytes만큼 읽어서 rBuff에 저장
    readLen = read(0, rBuff, BUFSIZ - 1);
    if (readLen == -1) {
        fprintf(stderr, "Read Error \n");
        return 0;
    }
    printf("Total reading data: %d\n", readLen);
    //dfdf
    rBuff[readLen] = '\0';      // 마지막에 \0 추가
    fD = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);
    if (fD == -1) {
        fprintf(stderr, "Open Error \n");
        return 0;
    }

    // fd에 readLen + 1만큼 rBuff의 값을 버퍼에 쓴다
    writeLen = write(fD, rBuff, readLen + 1);
    if (writeLen == -1) {
        fprintf(stderr, "Write Error \n");
        return 0;
    }
    printf("Total writing data: %d\n", readLen);

    close(fD);      // 사용한 fD 닫기

    return 0;
}