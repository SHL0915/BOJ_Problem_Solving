#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
    int Arr[3];
    int i, j, temp;
    scanf("%d %d %d", &Arr[0], &Arr[1], &Arr[2]);


    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            if (Arr[i] >= Arr[j]) {
                temp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = temp;
            }
        }
    }

    printf("%d", Arr[1]);

    return 0;
}