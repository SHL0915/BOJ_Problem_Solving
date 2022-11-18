#include <iostream>
using namespace std;

int N, M;
int arr[1000001];

long long BinarySearch(long long left, long long right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	long long ans = BinarySearch(0, 1000000000000);
	cout << ans;
	return 0;
}

long long BinarySearch(long long left, long long right) {
	if (left < right) {
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < N; i++) cnt += (mid / arr[i]);
		if (cnt < M) return BinarySearch(mid + 1, right);
		else return BinarySearch(left, mid);
	}
	else return left;
}