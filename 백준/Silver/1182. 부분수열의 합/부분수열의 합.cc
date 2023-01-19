#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, S, ans;
int arr[21];

void solve() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 1; i < (1 << N); i++) {
		int bit = 1, idx = 0, sum = 0;
		while (bit <= i) {
			if (bit & i) sum += arr[idx];
			idx++;
			bit <<= 1;
		}
		if (sum == S) ans++;
	}
	cout << ans << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}