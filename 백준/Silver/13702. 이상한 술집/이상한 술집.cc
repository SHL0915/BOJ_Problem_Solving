#include <iostream>
#include <algorithm>
using namespace std;

long long N, K;
long long drink[10000];

long long BinarySearch(long long left, long long right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> drink[i];
	long long ans = BinarySearch(1, (1LL << 32));
	long long cnt = 0;
	for (int i = 0; i < N; i++) cnt += drink[i] / ans;
	if (cnt < K) cout << ans - 1;
	else cout << ans;
	return 0;
}

long long BinarySearch(long long left, long long right) {
	long long mid = (left + right) / 2;
	if (left < right) {
		long long cnt = 0;
		for (int i = 0; i < N; i++) cnt += drink[i] / mid;
		if (cnt < K) return BinarySearch(left, mid - 1);
		else return BinarySearch(mid + 1, right);
	}
	else return mid;
}