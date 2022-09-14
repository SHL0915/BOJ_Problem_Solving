#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 500005;

int N, K, cnt = 0;
int Arr[MAX_N];
int temp[MAX_N];

void MergeSort(int left, int right_end);
void Merge(int left, int right, int right_end);

int main(void) {	
	cin >> N >> K;	
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	MergeSort(0, N - 1);
	cout << "-1";
	return 0;
}

void MergeSort(int left, int right_end) {	
	if (left < right_end) {
		int mid = (left + right_end) / 2;
		MergeSort(left, mid);
		MergeSort(mid + 1, right_end);
		Merge(left, mid + 1, right_end);
	}
	return;
}

void Merge(int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while (i < right && j <= right_end) {
		if (Arr[i] <= Arr[j]) {
			temp[pos++] = Arr[i++];						
			if (++cnt == K) {
				cout << Arr[i - 1];
				exit(0);
			}
		}
		else {
			temp[pos++] = Arr[j++];
			if (++cnt == K) {
				cout << Arr[j - 1];
				exit(0);
			}
		}
	}
	while (i < right) {
		temp[pos++] = Arr[i++];
		if (++cnt == K) {
			cout << Arr[i - 1];
			exit(0);
		}
	}
	while (j <= right_end) {
		temp[pos++] = Arr[j++];
		if (++cnt == K) {
			cout << Arr[j - 1];
			exit(0);
		}
	}
	for (i = left; i <= right_end; i++)
		Arr[i] = temp[i];
	return;
}