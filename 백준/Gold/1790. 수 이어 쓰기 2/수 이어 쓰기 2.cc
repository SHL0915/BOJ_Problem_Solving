#include <iostream>
using namespace std;

long long N, K;

long long BinarySearch(long long left, long long right);
long long findLen(long long n);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	long long ans = BinarySearch(1LL, N);
	if (K > findLen(ans)) {
		cout << -1;
		return 0;
	}
	K -= findLen(ans - 1);
	string out = "";
	while (ans) {
		out = (char)(ans % 10 + '0') + out;
		ans /= 10;
	}
	cout << out[K - 1];
	return 0;
}

long long BinarySearch(long long left, long long right) {
	if (left < right) {
		long long mid = (left + right) / 2;
		if (K <= findLen(mid - 1)) return BinarySearch(left, mid - 1);
		else if (K <= findLen(mid)) return mid;
		else return BinarySearch(mid + 1, right);
	}
	else return left;
}

long long findLen(long long n) {
	long long ret = 0, cnt = 1;
	long long temp = 1;
	if (n < 10) return n;
	while (1) {
		if (temp * 10 > n) break;		
		ret += (9 * temp * cnt);
		temp *= 10;
		cnt++;
	}
	ret += (n - temp + 1) * cnt;
	return ret;
}