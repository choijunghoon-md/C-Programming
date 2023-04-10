#include<stdio.h>
#include<stdlib.h>

int* getNumbers() {
    static int arr[6] = { 1,2,3,4,5,6 };
    return arr;
}

int* getNumbers2_1() {
    static int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    return (int*)arr;
}

int* getNumbers2_2() {
    static int arr1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    return (int*)arr1;
}

void* getNumbers2_3() {
    static int arr2[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    return (void*)arr2;
}

int* getNumbers3_1() {
    static int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
    return (int*)arr;
}

int* getNumbers3_2() {
    static int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
    return (int*)arr;
}

void* getNumbers3_3() {
    static int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
    return (void*)arr;
}

int main(void) {
    int* nums1 = getNumbers();
    for (int i = 0; i < 6; i++) printf("%d ", nums1[i]);

    int* nums2_1 = getNumbers2_1();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf("%d ", *(nums2_1 + i * 3 + j));
        printf("| ");
    }

    int(*nums2_2)[3] = (void*)getNumbers2_2();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf("%d ", nums2_2[i][j]);
        printf("| ");
    }

    int(*nums2_3)[3] = getNumbers2_3();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf("%d ", nums2_3[i][j]);
        printf("| ");
    }

    int* nums3_1 = getNumbers3_1();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) printf("%d ", *(nums3_1 + 6 * i + 3 * j + k));
            printf(", ");
        }
        printf("| ");
    }

    int(*nums3_2)[2][3] = (void*)getNumbers3_2();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) printf("%d ", nums3_2[i][j][k]);
            printf(", ");
        }
        printf("| ");
    }

    int(*nums3_3)[2][3] = getNumbers3_3();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) printf("%d ", nums3_3[i][j][k]);
            printf(", ");
        }
        printf("| ");
    }

}