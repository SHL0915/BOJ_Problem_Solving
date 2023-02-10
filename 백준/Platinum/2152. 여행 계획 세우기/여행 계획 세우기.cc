#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, S, T, cnt, id_cnt;
vector <int> org[10001], graph[10001];
int par[10001], id[10001], table[10001];
vector <vector<int>> SCC;
stack <int> st;

int DFS(int node);
int DP(int node);

void solve() {
	cin >> N >> M >> S >> T;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		org[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) if (par[i] == 0) DFS(i);
	for (int i = SCC.size() - 1; i >= 0; i--) {
		for (int j = 0; j < SCC[i].size(); j++) {
			int now = SCC[i][j];
			for (int k = 0; k < org[now].size(); k++) {
				int next = org[now][k];
				if (id[now] == id[next]) continue;
				graph[id[now]].push_back(id[next]);
			}
		}
	}
	memset(table, -1, sizeof(table));
	int ans = DP(id[S]);
	if (ans < 0) cout << 0;
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

int DFS(int node) {
	par[node] = ++cnt;
	int ret = cnt;
	st.push(node);
	for (int i = 0; i < org[node].size(); i++) {
		int next = org[node][i];
		if (par[next] == 0) ret = min(ret, DFS(next));
		else if (id[next] == 0) ret = min(ret, par[next]);
	}
	if (ret == par[node]) {
		id_cnt++;
		vector <int> v;
		while (1) {
			int t = st.top();
			st.pop();
			id[t] = id_cnt;
			v.push_back(t);
			if (t == node) break;
		}
		SCC.push_back(v);
	}
	return ret;
}

int DP(int node) {
	if (node == id[T]) return SCC[id[T] - 1].size();
	int& ret = table[node];
	if (ret != -1) return ret;
	ret = -INF;
	for (int i = 0; i < graph[node].size(); i++) {
		ret = max(ret, (int)SCC[node - 1].size() + DP(graph[node][i]));
	}
	return ret;
}