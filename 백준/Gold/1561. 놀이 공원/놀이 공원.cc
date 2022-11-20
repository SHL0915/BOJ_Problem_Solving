#include <iostream>
using namespace std;

long long N, M, t, temp;
long long arr[10001];

long long BinarySearch(long long left, long long right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> arr[i];
	if (N <= M) {
		cout << N;
		return 0;
	}
	t = BinarySearch(0, 60000000000LL);
	t--;
	for (int i = 0; i < M; i++) temp += t / arr[i];
	N -= (temp + M);
	for (int i = 0; i < M; i++) {
		if ((t + 1) % arr[i] == 0) N--;
		if (N == 0) {
			cout << i + 1;
			return 0;
		}
	}
	return 0;
}

long long BinarySearch(long long left, long long right) {
	if (left < right) {
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < M; i++) cnt += (mid / arr[i]);
		if (cnt < N - M) return BinarySearch(mid + 1, right);
		else return BinarySearch(left, mid);
	}
	else return left;
}