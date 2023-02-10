#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt, id_cnt;
vector <int> graph[200001];
int id[200001];
int par[200001];
vector <vector<int>> SCC;
stack <int> st;

int DFS(int node);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) if (par[i] == 0) DFS(i);
	if (SCC.size() == 1) cout << "Yes";
	else cout << "No";
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
		vector <int> v;
		id_cnt++;
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