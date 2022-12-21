#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;

int t, N, M, cnt, id;
vector <int> graph[MAX];
int par[MAX];
int mark[MAX];
int SCC[MAX];
int indegree[MAX];
stack <int> s;

int DFS(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> N >> M;
		cnt = 0, id = 0;
		for (int i = 1; i <= N; i++) graph[i].clear();
		memset(par, 0, sizeof(par));
		memset(mark, 0, sizeof(mark));
		memset(SCC, 0, sizeof(SCC));
		memset(indegree, 0, sizeof(indegree));
		for (int i = 0; i < M; i++) {
			int A, B;
			cin >> A >> B;
			graph[A].push_back(B);
		}
		for (int i = 1; i <= N; i++) if (par[i] == 0) DFS(i);
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				int next = graph[i][j];
				if (SCC[i] != SCC[next]) indegree[SCC[next]]++;
			}
		}
		int ans = 0;
		for (int i = 0; i < cnt; i++) if (indegree[i] == 0) ans++;
		cout << ans << '\n';
	}
	return 0;
}

int DFS(int node) {
	par[node] = ++id;
	s.push(node);
	int ret = par[node];
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (par[next] == 0) ret = min(ret, DFS(next));
		else if (mark[next] == 0) ret = min(ret, par[next]);
	}
	if (ret == par[node]) {
		cnt++;
		while (1) {
			int t = s.top();
			s.pop();
			mark[t] = 1;
			SCC[t] = cnt;
			if (t == node) break;
		}
	}
	return ret;
}