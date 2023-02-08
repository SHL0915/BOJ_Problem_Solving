#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, tot;
int A[251];
int B[251];
int table[62501];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
	for (int i = 0; i < N; i++) tot += A[i];
	for (int i = 0; i < N; i++) {
		for (int j = 62500; j >= 0; j--) {
			if (j < B[i]) continue;
			table[j] = max(table[j], A[i] + table[j - B[i]]);
		}
	}
	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= 62500; i++) ans = min(ans, max(tot - table[i], i));
	cout << ans;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}