#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, L;
vector <int> val;
ll table[1005][1005][2];

ll DP(int left, int right, int pos);

void solve() {
	cin >> N >> L;
	val.push_back(L);
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		val.push_back(a);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	memset(table, -1, sizeof(table));
	L = lower_bound(val.begin(), val.end(), L) - val.begin();
	cout << DP(L, L, 0);
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

ll DP(int left, int right, int pos) {
	if (left == 0 && right == val.size() - 1) return 0;
	ll& ret = table[left][right][pos];
	if (ret != -1) return ret;
	ret = INF;
	ll now;
	ll cnt = val.size() - (right - left + 1);
	if (pos) now = val[right];
	else now = val[left];
	if (left > 0) ret = min(ret, (now - val[left - 1]) * cnt + DP(left - 1, right, 0));
	if (right < val.size() - 1) ret = min(ret, (val[right + 1] - now) * cnt + DP(left, right + 1, 1));
	return ret;
}