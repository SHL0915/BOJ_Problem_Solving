#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int N, L, R, X, ans;
int arr[15];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 1; i < (1 << N); i++) {
		long long bit_cnt = 0, sum = 0, max_diff = 0, max_val = 0, min_val = INF;
		int bit = 1;
		int cnt = 0;
		while (bit <= i) {
			if (bit & i) {
				bit_cnt++;
				sum += arr[cnt];
				max_val = max(max_val, (long long)arr[cnt]);
				min_val = min(min_val, (long long)arr[cnt]);
			}
			cnt++;
			bit <<= 1;
		}
		if (bit_cnt >= 2 && (L <= sum && sum <= R) && (max_val - min_val) >= X) ans++;
	}
	cout << ans;
	return 0;
}