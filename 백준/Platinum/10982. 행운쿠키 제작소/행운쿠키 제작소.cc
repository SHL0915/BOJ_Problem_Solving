#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, tot;
int A[1001];
int B[1001];
int table[100001];

void solve() {
	cin >> N;
	tot = 0;
	memset(table, 0, sizeof(table));
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
	for (int i = 0; i < N; i++) tot += A[i];
	for (int i = 0; i < N; i++) {
		for (int j = 100000; j >= 0; j--) {
			if (j < B[i]) continue;
			table[j] = max(table[j], A[i] + table[j - B[i]]);
		}
	}
	int ans = INF;
	for (int i = 0; i <= 100000; i++) ans = min(ans, max(tot - table[i], i));
	cout << ans << '\n';
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}