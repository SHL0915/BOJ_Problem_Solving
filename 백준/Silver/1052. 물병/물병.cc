#include <iostream>
using namespace std;

long long N, K, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (long long i = N; ; i++) {
		long long bit = 1;
		int cnt = 0;
		for (int j = 0; j <= 32; j++) {
			if (bit & i) cnt++;
			bit <<= 1;
		}
		if (cnt <= K) {
			ans = i - N;
			break;
		}
	}
	cout << ans;
	return 0;
}