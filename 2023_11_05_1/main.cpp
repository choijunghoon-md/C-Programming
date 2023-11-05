#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt = 0;

int main() {
    int ringbuffer[5] = { 0, };
    while (1) {
        
        for (int i = 0; i < 5; i++) {
            printf("%d  ", ringbuffer[i]);
        }

        printf("\n\n");

        int temp = 0;
        
        printf("°ªÀ» ÀÔ·ÂÇÏ½Ã¿À : ");
        scanf("%d", &temp);
        
        ringbuffer[cnt] = temp;
        cnt++;
        if(cnt >= 5){
            cnt = 0;
        }
    }
    return 0;
}
