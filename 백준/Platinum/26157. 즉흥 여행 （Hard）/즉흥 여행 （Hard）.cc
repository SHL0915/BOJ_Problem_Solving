#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt, id_cnt;
vector <int> org[200001], graph[200001];
int par[200001], id[200001], in_degree[200001];
vector <vector<int>> SCC;
stack <int> st;

int DFS(int node);
void Topology();

void solve() {
	cin >> N >> M;
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
				in_degree[id[next]]++;
			}
		}
	}
	Topology();
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
		vector <int> v;
		id_cnt++;
		while (1) {
			int t = st.top();
			st.pop();
			id[t] = id_cnt;
			v.push_back(t);
			if (t == node) break;
		}
		sort(v.begin(), v.end());
		SCC.push_back(v);
	}
	return ret;
}

void Topology() {
	queue <int> q;
	for (int i = 1; i <= id_cnt; i++) if (in_degree[i] == 0) q.push(i);
	int ans = q.front() - 1;
	for (int i = 1; i <= id_cnt; i++) {
		if (q.size() != 1) {
			cout << 0;
			return;
		}
		int now = q.front();
		q.pop();
		for (int j = 0; j < graph[now].size(); j++) {
			if (--in_degree[graph[now][j]] == 0) q.push(graph[now][j]);
		}
	}
	cout << SCC[ans].size() << '\n';
	for (int i = 0; i < SCC[ans].size(); i++) cout << SCC[ans][i] << " ";
	return;
}
