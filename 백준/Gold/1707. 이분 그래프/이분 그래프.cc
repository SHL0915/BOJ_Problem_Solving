#include <iostream>
#include <vector>
using namespace std;

int K, V, E, flag;
vector <int> graph[20001];
vector <int> A, B;
int mark[20001];

void DFS(int vertex, int type);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> K;
	while (K--) {
		flag = 0;
		cin >> V >> E;
		for (int i = 1; i <= V; i++) {
			graph[i].clear();
			mark[i] = -1;
		}
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int i = 1; i <= V; i++) if (mark[i] == -1) DFS(i, 0);		
		if (flag == 1) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}

void DFS(int vertex, int type) {
	if (mark[vertex] != -1 && mark[vertex] != type) flag = 1;
	if (mark[vertex] != -1) return;
	mark[vertex] = type;	
	for (int i = 0; i < graph[vertex].size(); i++) DFS(graph[vertex][i], (type + 1) % 2);
	return;
}