#include <bits/stdc++.h>
using namespace std;

int V, E, id = 1;
int d[10001];
int mark[10001];
vector <int> graph[10001];
vector <vector<int>> SCC;
stack <int> s;

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
	for (int i = 1; i <= V; i++) if (d[i] == 0) DFS(i);
	sort(SCC.begin(), SCC.end());
	cout << SCC.size() << '\n';
	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) cout << SCC[i][j] << " ";
		cout << -1 << '\n';
	}
	return 0;
}

int DFS(int node) {
	d[node] = id++;
	s.push(node);
	int parent = d[node];
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (d[next] == 0) parent = min(parent, DFS(next));
		else if (mark[next] == 0) parent = min(parent, d[next]);
	}
	if (parent == d[node]) {
		vector <int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			mark[t] = 1;
			if (t == node) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}
	return parent;
}