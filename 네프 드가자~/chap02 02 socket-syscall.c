//���ص� - 90%

#include <sys/socket.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    int sD1, fD1, sD2, fD2; //���� 4�� ���� ��

    sD1 = socket(PF_INET, SOCK_STREAM, 0);      // IPv4, TCP ����, TCP �������� ���ϸ����
    fD1 = open("test1", O_RDONLY | O_CREAT);    //���ϸ����
    sD2 = socket(PF_INET, SOCK_STREAM, 0);      //���ϸ����
    fD2 = open("test2", O_RDONLY | O_CREAT);    //���ϸ���� 

    printf("sD1:%d, fD1:%d, sD2:%d, fD2:%d \n", sD1, fD1, sD2, fD2);

    close(sD1);
    close(fD1);
    close(sD2);
    close(fD2);

    return 0;
}


//���ϵ� �ᱹ �������·� ������
