#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int ringbuffer[5] = { 0, };
    while (1) {
        
        for (int i = 0; i < 5; i++) {
            printf("%d  ", ringbuffer[i]);
        }

        printf("\n\n");

        int temp = 0;
        
        printf("값을 입력하시오 : ");
        scanf("%d", &temp);

        for (int i = 3; i >= 0; i--) {
            ringbuffer[i + 1] = ringbuffer[i];
        }
        ringbuffer[0] = temp;
    }
    return 0;
}