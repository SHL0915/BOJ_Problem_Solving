#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int arr[(1 << 12)];
set <int> s;
vector <int> graph[(1 << 12)];
int table[(1 << 12)][(1 << 12)][2];

int DP(int node, int par, int turn);

void solve() {
	cin >> N;
	int a = 1;
	for (int i = 0; i < N; i++) {
		s.insert(a);
		a *= 2;
		s.insert(a - 1);
	}
	for (int i = 1; i < (1 << N); i++) cin >> arr[i];
	for (int i = 1; i < (1 << N); i++) {
		if (s.count(i)) {
			if (i % 2) {
				graph[i].push_back(i - 1);
				graph[i - 1].push_back(i);
			}
			else {
				graph[i].push_back(i + 1);
				graph[i + 1].push_back(i);
			}
		}
		else {
			graph[i].push_back(i - 1);
			graph[i - 1].push_back(i);
			graph[i].push_back(i + 1);
			graph[i + 1].push_back(i);
		}
		graph[i].push_back(i / 2);
	}	

	memset(table, -1, sizeof(table));

	for (int i = 1; i < (1 << N); i++) {
		cout << DP(i, 0, 0) << " ";
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

int DP(int node, int par, int turn) {
	if (node == 1) return arr[node];
	int & ret = table[node][par][turn];
	if (ret != -1) return ret;
	ret = arr[node];
	if (turn == 0) {
		int val = 0;
		for (int i = 0; i < graph[node].size(); i++) {
			int now = graph[node][i];
			if (now == par) continue;
			val = min(val, DP(now, node, turn ^ 1));
		}
		ret += val;
		return ret;
	}
	else {
		int val = 0;
		for (int i = 0; i < graph[node].size(); i++) {
			int now = graph[node][i];
			if (now == par) continue;
			val = max(val, DP(now, node, turn ^ 1));
		}
		ret += val;
		return ret;
	}
}