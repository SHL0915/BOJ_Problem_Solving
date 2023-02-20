#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[200001];
vector <int> graph[200001];
int table[200001][2];

int DP(int node, int type);

void solve() {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		int a; cin >> a;
		graph[a].push_back(i);
	}
	for (int i = 1; i <= N; i++) cin >> arr[i];
	memset(table, -1, sizeof(table));
	cout << max(DP(1, 0), DP(1, 1));
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

int DP(int node, int type) {
	int& ret = table[node][type];
	if (ret != -1) return ret;
	ret = 0;
	if (type == 0) {
		int tot = 0;
		int val = 0x3f3f3f3f;
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i];
			tot += DP(next, 0);
			val = min(val, DP(next, 0) - (DP(next, 1) + arr[node] * arr[next]));
		}
		ret = max(ret, tot - val);
	}
	int val = 0;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		val += DP(next, 0);
	}
	ret = max(ret, val);
	return ret;
}