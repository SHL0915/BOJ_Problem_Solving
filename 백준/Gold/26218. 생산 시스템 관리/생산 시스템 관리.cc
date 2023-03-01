#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f;

int N, B;
ll P[10], A[10], C[10];
ll table[10][30001];
int path[10][30001];

ll DP(int pos, int b);

void solve() {
	cin >> N >> B;
	for (int i = 0; i < N; i++) cin >> P[i] >> A[i] >> C[i];
	memset(table, -1, sizeof(table));

	cout << DP(0, 0) << '\n';

	int pos = 0, b = 0;
	while (1) {
		if (pos == N) break;
		cout << path[pos][b] << " ";
		b += C[pos] * path[pos][b];
		pos++;
	}
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

ll DP(int pos, int b) {
	if (b > B) return -INF;
	if (pos == N) return 1;
	ll& ret = table[pos][b];
	if (ret != -1) return ret;
	ret = 0;

	ll val = 0, idx = 0;
	for (int i = 0; i <= 100; i++) {
		ll now = min(100LL, (P[pos] + i * A[pos])) * DP(pos + 1, b + i * C[pos]);
		if (now > val) {
			val = now;
			idx = i;
		}
	}

	path[pos][b] = idx;
	ret = val;
	return ret;
}