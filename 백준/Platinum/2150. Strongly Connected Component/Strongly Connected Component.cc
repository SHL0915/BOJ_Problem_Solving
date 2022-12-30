#include <bits/stdc++.h>
using namespace std;

int V, E, id;
vector <int> graph[10001];
int par[10001];
int mark[10001];
stack <int> s;
vector <vector<int>> SCC;

int DFS(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
	}
	for (int i = 1; i <= V; i++) if (par[i] == 0) DFS(i);
	sort(SCC.begin(), SCC.end());
	cout << SCC.size() << '\n';
	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) cout << SCC[i][j] << " ";
		cout << "-1\n";
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
			if (t == node) break;
		}
		sort(v.begin(), v.end());
		SCC.push_back(v);
	}
	return ret;
}