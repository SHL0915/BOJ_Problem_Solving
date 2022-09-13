#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Merge(int Arr[], int temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while ((i <= right - 1) && (j <= right_end)) {
		if (Arr[i] <= Arr[j]) {
			temp[pos] = Arr[i];
			i++;
			pos++;
		}
		else {
			temp[pos] = Arr[j];
			j++;
			pos++;
		}
	}
	while (i <= right - 1) {
		temp[pos] = Arr[i];
		i++;
		pos++;
	}
	while (j <= right_end) {
		temp[pos] = Arr[j];
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++) {
		Arr[i] = temp[i];
	}
	return;
}


void MergeSort(int Arr[], int temp[], int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
	else
		return;
}


int val[10001] = { 0 };

int main(void) {
	int n, k, i, j;
	int Arr[100], temp[100];

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++) {
		scanf("%d", &Arr[i]);
	}

	MergeSort(Arr, temp, 0, n - 1);
		

	for (i = 0; i < n; i++) {
		for (j = 1; j <= k; j++) {
			if (Arr[i] > j)
				continue;
			else if (Arr[i] == j) {
				val[j] ++;
			}
			else {
				val[j] += val[j - Arr[i]];
			}			
		}
	}	

	printf("%d", val[k]);	

	return 0;
}