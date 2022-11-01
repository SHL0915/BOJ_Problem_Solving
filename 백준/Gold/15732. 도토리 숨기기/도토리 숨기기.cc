#include <iostream>
using namespace std;

long long N, K, D, ans;
long long rule[10000][3];

long long BinarySearch(long long left, long long right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K >> D;
	for (int i = 0; i < K; i++) cin >> rule[i][0] >> rule[i][1] >> rule[i][2];
	ans = BinarySearch(1, N);
	cout << ans;
	return 0;
}

long long BinarySearch(long long left, long long right) {
	long long mid = (left + right) / 2;
	if (left < right) {
		long long cnt = 0;
		for (int i = 0; i < K; i++) {
			if (mid < rule[i][0]) continue;
			else if (mid <= rule[i][1]) cnt += (1 + (mid - rule[i][0]) / rule[i][2]);
			else cnt += (1 + (rule[i][1] - rule[i][0]) / rule[i][2]);
		}
		if (cnt >= D) return BinarySearch(left, mid);
		else return BinarySearch(mid + 1, right);
	}
	else return mid;
}