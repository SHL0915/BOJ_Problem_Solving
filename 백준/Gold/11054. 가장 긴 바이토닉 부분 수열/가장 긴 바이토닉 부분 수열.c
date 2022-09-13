#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int val[1000] = {0};

void dp(int Arr[], int val[], int pos, int N) {
	int i, temp;
	if (val[pos] == 0) {
		temp = 0;
		for (i = pos; i >= 0; i--) {
			if (Arr[pos] > Arr[i])
				if (temp <= val[i])
					temp = val[i];
		}
		val[pos] = temp + 1;
	}
	else
		return;
}

void dpdown(int Arr[], int val[], int pos, int N) {
	int i, temp;
	if (val[pos] == 0) {
		temp = 0;
		for (i = pos; i < N; i++) {
			if(Arr[i]<Arr[pos])
				if (temp <= val[i])
					temp = val[i];
		}
		val[pos] = temp + 1;
	}
	else
		return;
}

int main(void) {
	int N, i, j, temp1, temp2, max = 0;
	int *Arr;

	scanf("%d", &N);

	Arr = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}

	for (i = 0; i < N; i++) {
		temp1 = 0;
		temp2 = 0;
		if (i == 0) {
			temp1 = 1;
			val[N - 1] = 1;
			for (j = N - 1; j >= i + 1; j--) {
				dpdown(Arr, val, j, N);
			}
			for (j = i + 1; j < N; j++) {
				if (Arr[i] > Arr[j])
					if (temp2 <= val[j])
						temp2 = val[j];
			}
		}
		else if (i == N - 1) {
			val[0] = 1;
			for (j = 0; j <= i - 1; j++) {
				dp(Arr, val, j, i);
			}
			for (j = 0; j <= i - 1; j++) {
				if (Arr[j] < Arr[i])
					if (temp1 <= val[j])
						temp1 = val[j] + 1;
			}
		}
		else
		{
			val[0] = 1;
			for (j = 0; j <= i-1; j++) {
				dp(Arr, val, j, i);
			}
			for (j = 0; j <= i - 1; j++) {
				if (Arr[j] < Arr[i])
					if (temp1 <= val[j])
						temp1 = val[j] + 1;
			}
			val[N - 1] = 1;
			for (j = N - 1; j >= i + 1; j--) {
				dpdown(Arr, val, j, N);
			}


			for (j = i + 1; j < N; j++) {
				if (Arr[i] > Arr[j])
					if (temp2 <= val[j])
						temp2 = val[j];
			}
		}
		for (j = 0; j < N; j++)
			val[j] = 0;
		if (max <= temp1 + temp2) {
			max = temp1 + temp2;
		}
	}

	printf("%d", max);
}