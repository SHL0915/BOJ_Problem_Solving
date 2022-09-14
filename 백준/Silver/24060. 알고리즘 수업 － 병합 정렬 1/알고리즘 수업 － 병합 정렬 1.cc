#include <iostream>
using namespace std;

int cnt = 0;
int num = -1;

void MergeSort(int* Arr, int* temp, int left, int right_end, int K);
void Merge(int* Arr, int* temp, int left, int right, int right_end, int K);

int main(void) {
	int N, K;
	cin >> N >> K;
	int* Arr = (int*)malloc(sizeof(int) * N);
	int* temp = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	MergeSort(Arr, temp, 0, N - 1, K);
	cout << num;
	return 0;
}

void MergeSort(int* Arr, int* temp, int left, int right_end, int K) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid, K);
		MergeSort(Arr, temp, mid + 1, right_end, K);
		Merge(Arr, temp, left, mid + 1, right_end, K);
	}
	return;
}

void Merge(int* Arr, int* temp, int left, int right, int right_end, int K) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while (i < right && j <= right_end) {
		if (Arr[i] <= Arr[j]) {
			temp[pos] = Arr[i];
			i++;
			pos++;
			cnt++;			
			if (cnt == K)
				num = Arr[i - 1];
		}
		else {
			temp[pos] = Arr[j];
			j++;
			pos++;
			cnt++;			
			if (cnt == K)
				num = Arr[j - 1];
		}
	}
	while (i < right) {
		temp[pos] = Arr[i];
		i++;
		pos++;
		cnt++;		
		if (cnt == K)
			num = Arr[i - 1];
	}
	while (j <= right_end) {
		temp[pos] = Arr[j];
		j++;
		pos++;
		cnt++;		
		if (cnt == K)
			num = Arr[j - 1];
	}
	for (i = left; i <= right_end; i++)
		Arr[i] = temp[i];
	return;
}