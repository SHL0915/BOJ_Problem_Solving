#include <bits/stdc++.h>
using namespace std;
const int MAX = 200005;

int t, N, M, id;
vector <int> graph[MAX];
int par[MAX];
int mark[MAX];
int in_degree[MAX];
int SCC_id[MAX];
vector <vector<int>> SCC;
stack <int> s;

int DFS(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> N >> M;
		id = 0;
		for (int i = 0; i < N; i++) graph[i].clear();
		for (int i = 0; i < SCC.size(); i++) SCC[i].clear();
		SCC.clear();
		memset(par, 0, sizeof(par));
		memset(mark, 0, sizeof(mark));
		memset(in_degree, 0, sizeof(in_degree));
		memset(SCC_id, 0, sizeof(SCC_id));
		for (int i = 0; i < M; i++) {
			int A, B;
			cin >> A >> B;
			graph[A].push_back(B);
		}
		for (int i = 0; i < N; i++) if (par[i] == 0) DFS(i);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				int next = graph[i][j];
				if (SCC_id[i] != SCC_id[next]) in_degree[SCC_id[next]]++;
			}
		}
		int temp = 0;
		for (int i = 0; i < SCC.size(); i++) {
			if (in_degree[i] == 0) temp++;
		}
		if (temp >= 2) cout << "Confused\n";
		else {
			for (int i = 0; i < SCC.size(); i++) {
				if (in_degree[i] == 0) {
					for (int j = 0; j < SCC[i].size(); j++) cout << SCC[i][j] << '\n';
				}
			}
		}
		cout << '\n';
	}
	return 0;
}

int DFS(int node) {
	par[node] = ++id;
	int ret = par[node];
	s.push(node);
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (par[next] == 0) ret = min(ret, DFS(next));
		else if (mark[next] == 0) ret = min(ret, par[next]);
	}
	if (ret == par[node]) {
		vector <int> v;
		while (1) {
			int t = s.top();
			s.pop();
			mark[t] = 1;
			v.push_back(t);
			SCC_id[t] = SCC.size();
			if (t == node) break;
		}
		sort(v.begin(), v.end());
		SCC.push_back(v);
	}
	return ret;
}