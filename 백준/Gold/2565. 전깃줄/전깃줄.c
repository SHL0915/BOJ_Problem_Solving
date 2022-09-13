#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int val[500] = { 0 };

void dp(int Arr[], int val[], int pos, int N) {
	int i, temp;
	if (val[pos] == 0) {
		temp = 0;
		for (i = pos; i <= N; i++) {	
			if (Arr[i] > Arr[pos])
				if (temp <= val[i])
					temp = val[i];
		}
		val[pos] = temp + 1;
	}
	else
		return;
}

int main(void) {
	int N, i,j=0, max = 0;
	int index, value;
	int* Arr, *temp;

	scanf("%d", &N);

	Arr = (int*)malloc(sizeof(int) * 500);
	temp = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < 500; i++) {
		Arr[i] = 0;
	}

	for (i = 0; i < N; i++) {
		scanf("%d %d", &index, &value);
		Arr[index - 1] = value;
	}

	for (i = 0; i < 500; i++) {
		if (Arr[i] != 0) {
			temp[j] = Arr[i];
			j++;
		}
	}
	
	val[j-1] = 1;

	for (i= j-1; i >= 0; i--) {
		dp(temp, val, i, j-1);
	}
	

	for (i = 0; i < j; i++) {
		if (max <= val[i])
			max = val[i];
	}

	printf("%d", N - max);

}