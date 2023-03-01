#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int L, P, V, k;

void solve() {
	int cnt = V / P;
	int ans = L * cnt;
	ans += min(V % P, L);

	cout << "Case " << k << ": ";
	cout << ans << '\n';
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
	while (1) {
		k++;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) break;
		solve();
	}
	return 0;
}