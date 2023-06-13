#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
string arr[15];
vector <string> v;
vector <int> id[15];
map <string, int> convert;
int len[500005];
int table[15][500005];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 1; j < (1 << (arr[i].length())); j++) {
			string s = "";
			int now = j, idx = 0;
			while (now) {
				if (now % 2) s += arr[i][idx];
				now /= 2;
				idx++;
			}
			v.push_back(s);
		}
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		convert[v[i]] = i + 1;
		len[i + 1] = v[i].length();
	}
		
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < (1 << (arr[i].length())); j++) {
			string s = "";
			int now = j, idx = 0;
			while (now) {
				if (now % 2) s += arr[i][idx];
				now /= 2;
				idx++;
			}
			id[i].push_back(convert[s]);
		}
		sort(id[i].begin(), id[i].end());
		id[i].erase(unique(id[i].begin(), id[i].end()), id[i].end());
	}

	for (int i = 0; i < id[0].size(); i++) table[0][id[0][i]] = len[id[0][i]];
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= 500000; j++) table[i - 1][j] = max(table[i - 1][j], table[i - 1][j - 1]);

		for (int j = 0; j < id[i].size(); j++) {
			int now = id[i][j];
			if (table[i - 1][now - 1] == 0) continue;
			table[i][now] = len[now] + table[i - 1][now - 1];
		}
	}

	int ans = 0;
	for (int i = 0; i <= 500000; i++) ans = max(ans, table[N - 1][i]);

	if (ans == 0) cout << -1;
	else cout << ans;

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