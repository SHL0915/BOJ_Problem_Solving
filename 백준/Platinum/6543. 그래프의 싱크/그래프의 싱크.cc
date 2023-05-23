#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt, id_cnt;
vector <int> graph[5005];
int par[5005], id[5005], out_degree[5005];
stack <int> st;

void init();
int DFS(int node);

void solve() {
	while (1) {
		cin >> N;
		if (N == 0) break;
		cin >> M;
		init();
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
		}

		for (int i = 1; i <= N; i++) if (par[i] == 0) DFS(i);
		
		vector <int> ans;

		for (int i = 1; i <= N; i++) {
			for (int j : graph[i]) {
				if (id[i] != id[j]) out_degree[id[i]]++;
			}
		}

		for (int i = 1; i <= N; i++) if (out_degree[id[i]] == 0) ans.push_back(i);

		for (int i : ans) cout << i << " ";
		cout << '\n';
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

void init() {
	for (int i = 1; i <= N; i++) {
		graph[i].clear();
		par[i] = 0;
		id[i] = 0;
		out_degree[i] = 0;
	}
	cnt = 0;
	id_cnt = 0;
	return;
}

int DFS(int node) {
	par[node] = ++cnt;
	int ret = cnt;
	st.push(node);
	
	for (int next : graph[node]) {
		if (par[next] == 0) ret = min(ret, DFS(next));
		else if (id[next] == 0) ret = min(ret, par[next]);
	}

	if (ret == par[node]) {
		id_cnt++;
		while (1) {
			int t = st.top(); st.pop();
			id[t] = id_cnt;
			if (t == node) break;
		}
	}

	return ret;
}