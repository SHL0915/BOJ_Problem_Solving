#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt, id_cnt;
vector <int> graph[100001];
int par[100001], id[100001], in_degree[100001];
stack <int> st;

int DFS(int node);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for (int i = 0; i < N; i++) if (par[i] == 0) DFS(i);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int now = graph[i][j];
			if (id[i] != id[now]) in_degree[id[now]]++;
		}
	}

	int ans = 0;
	for (int i = 1; i <= id_cnt; i++) if (in_degree[i] == 0) ans++;

	cout << ans;
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
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (par[next] == 0) ret = min(ret, DFS(next));
		else if (id[next] == 0) ret = min(ret, par[next]);
	}

	if (ret == par[node]) {
		id_cnt++;
		while (1) {
			int t = st.top();
			st.pop();
			id[t] = id_cnt;
			if (t == node) break;
		}
	}
	return ret;
}