#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Search(int Arr[], int left, int right, int N) {
	int mid = (left + right) / 2;
	int temp;
	if (left < right) {
		if (Arr[mid] < N) {
			temp = Search(Arr, mid + 1, right, N);
		}
		else {
			temp = Search(Arr, left, mid, N);
		}
	}
	else
		return mid;
}

int main(void) {
	int N, i,j, index;
	int* Arr, *temp;
	int len = 0;

	scanf("%d", &N);

	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++)
		scanf("%d", &Arr[i]);

	temp[0] = Arr[0];

	for (i = 1; i < N; i++) {
		if (Arr[i] > temp[len]) {
			len++;
			temp[len] = Arr[i];
		}	
		else { 
			index = Search(temp, 0, len, Arr[i]);
			temp[index] = Arr[i];
		}			
		
	}


	if (N == 0) {
		printf("0");
	}
	else
		printf("%d", len + 1);
}