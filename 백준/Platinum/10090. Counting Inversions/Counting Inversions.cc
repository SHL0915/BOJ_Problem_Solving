#include <iostream>
using namespace std;

long long N, ans;
long long arr[1000000];
long long temp[1000000];

void MergeSort(long long arr[1000000], long long temp[1000000], long long left, long long right_end);
void Merge(long long arr[1000000], long long temp[1000000], long long left, long long right, long long right_end);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	MergeSort(arr, temp, 0, N - 1);
	cout << ans;
	return 0;
}

void MergeSort(long long arr[1000000], long long temp[1000000], long long left, long long right_end) {
	long long mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(arr, temp, left, mid);
		MergeSort(arr, temp, mid + 1, right_end);
		Merge(arr, temp, left, mid + 1, right_end);
	}
	else return;
}

void Merge(long long arr[1000000], long long temp[1000000], long long left, long long right, long long right_end) {
	long long i = left, j = right, pos = left;
	while (i < right && j <= right_end) {
		if (arr[i] <= arr[j]) temp[pos++] = arr[i++];
		else {
			ans += right - i;
			temp[pos++] = arr[j++];
		}
	}
	while (i < right) temp[pos++] = arr[i++];
	while (j <= right_end) temp[pos++] = arr[j++];
	for (long long i = left; i <= right_end; i++) arr[i] = temp[i];
	return;
}