#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Backtracking(int* Arr, int* temp, int* mark, int N, int k, int start) {
	int i;
	if (k == 6) {
		for (i = 0; i < 6; i++) {
			printf("%d ", temp[i]);
		}
		printf("\n");
		return;
	}
	else {
		for (i = start; i < N; i++) {
			if (mark[i] == 0) {
				mark[i] = 1;
				temp[k] = Arr[i];
				Backtracking(Arr, temp, mark, N, k + 1, i);
				mark[i] = 0;
			}
		}
	}
}

int main(void){
	int k, * Arr, *temp, *mark, i; // 원소의 개수가 k인 배열 Arr, Backtracking한 배열을 저장하는 temp	
	while(1) {
		scanf("%d", &k);
		if (k == 0)
			break;
		Arr = (int*)malloc(sizeof(int) * k);
		mark = (int*)malloc(sizeof(int) * k);
		temp = (int*)malloc(sizeof(int) * 6);
		for (i = 0; i < k; i++) {
			scanf("%d", &Arr[i]);
			mark[i] = 0;
		}
		for (i = 0; i < k - 5; i++) { // 시작점 index의 범위는 0 ~ k-6
			if (mark[i] == 0) {
				mark[i] = 1; // 이미 선택한 항목을 표시
				temp[0] = Arr[i];
				Backtracking(Arr, temp, mark, k, 1, i);
				mark[i] = 0;
			}
		}
		free(Arr);
		free(mark);
		free(temp);
		printf("\n");
	}
	return 0;
}