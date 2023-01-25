#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
vector <int> graph[1000001];
int table[1000001][2];

int DP(int node, int mode, int par);

void solve() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	memset(table, -1, sizeof(table));
	cout << min(DP(1, 0, -1), DP(1, 1, -1));
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

int DP(int node, int mode, int par) {
	int& ret = table[node][mode];
	if (ret != -1) return ret;
	ret = mode;
	if (mode) {
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i];
			if (next == par) continue;
			ret += min(DP(next, 0, node), DP(next, 1, node));
		}
	}
	else {
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i];
			if (next == par) continue;
			ret += DP(next, 1, node);
		}
	}
	return ret;
}