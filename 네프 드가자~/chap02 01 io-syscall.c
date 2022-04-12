//���ص� - 95%

#include <stdio.h>
#include <fcntl.h>


//�׽�Ʈ ��� : ./io-syscall test.txt (����) How old are you?(����)
int main(int argc, char** argv) {
    int fD, writeLen, readLen;
    char rBuff[BUFSIZ];     // default 8192

    // ��� ���� ����üũ ����
    if (argc != 2) {
        fprintf(stderr, "Usage : %s [Filename] \n", argv[0]);
        return 0;
    }


    // Ű����(fD:0)�κ��� BUFSIZ-1 bytes��ŭ �о rBuff�� ����
    readLen = read(0, rBuff, BUFSIZ - 1);
    if (readLen == -1) {
        fprintf(stderr, "Read Error \n");
        return 0;
    }
    printf("Total reading data: %d\n", readLen);
    //dfdf
    rBuff[readLen] = '\0';      // �������� \0 �߰�
    fD = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);
    if (fD == -1) {
        fprintf(stderr, "Open Error \n");
        return 0;
    }

    // fd�� readLen + 1��ŭ rBuff�� ���� ���ۿ� ����
    writeLen = write(fD, rBuff, readLen + 1);
    if (writeLen == -1) {
        fprintf(stderr, "Write Error \n");
        return 0;
    }
    printf("Total writing data: %d\n", readLen);

    close(fD);      // ����� fD �ݱ�

    return 0;
}