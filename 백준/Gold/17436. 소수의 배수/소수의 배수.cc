#include <bits/stdc++.h>
using namespace std;

long long N, M, ans;
long long arr[10];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 1; i < (1 << N); i++) {
		long long now = 1, bit = 1, idx = 0, cnt = 0;
		while (bit <= i) {
			if (bit & i) {
				now *= arr[idx];
				cnt++;
			}
			bit <<= 1;
			idx++;
		}
		if (cnt % 2) ans += (M / now);
		else ans -= (M / now);
	}
	cout << ans;
	return 0;
}