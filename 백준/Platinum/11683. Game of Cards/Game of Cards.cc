#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int P, K;
vector <int> arr[105];
int table[105][1005];

int DP(int pile, int now);

void solve() {
	cin >> P >> K;
	for (int i = 0; i < P; i++) {
		int N; cin >> N;
		arr[i].push_back(0);
		for (int j = 1; j <= N; j++) {
			int a; cin >> a;
			arr[i].push_back(a);
		}
	}

	memset(table, -1, sizeof(table));
	int ans = DP(0, arr[0].size() - 1);
	for (int i = 1; i < P; i++) ans ^= DP(i, arr[i].size() - 1);
		
	if (ans) cout << "Alice can win.";
	else cout << "Bob will win.";

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

int DP(int pile, int now) {
	if (now < 0) return -1;
	if (now == 0) return 0;
	int& ret = table[pile][now];
	if (ret != -1) return ret;
	ret = 0;

	set <int> s;
	for (int i = 0; i <= K; i++) {
		if (now - i < 1) break;
		int val = DP(pile, now - i - arr[pile][now - i]);
		if (val == -1) continue;
		s.insert(DP(pile, now - i - arr[pile][now - i]));
	}

	for (auto i = s.begin(); i != s.end(); i++) {
		if ((*i) != ret) break;
		ret++;
	}

	return ret;
}