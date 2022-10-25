#include <iostream>
#include <vector>
using namespace std;

int N;
vector <int> tree[100000];
int parent[100000];
int mark[100000];

void DFS(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u - 1].push_back(v - 1);
		tree[v - 1].push_back(u - 1);
	}
	DFS(0);
	for (int i = 1; i < N; i++) cout << parent[i] << '\n';
	return 0;
}

void DFS(int node) {
	if (mark[node] != 0) return;
	mark[node] = 1;
	for (int i = 0; i < tree[node].size(); i++) {
		if (mark[tree[node][i]] == 0) {
			parent[tree[node][i]] = node + 1;
			DFS(tree[node][i]);
		}
	}
}