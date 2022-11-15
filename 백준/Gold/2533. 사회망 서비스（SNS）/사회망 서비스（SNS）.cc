#include <iostream>
#include <vector>
using namespace std;

int N, ans;
vector <int> tree[1000001];
int table[1000001][2];

int DFS(int node, int parent, int type);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}	
	for (int i = 1; i <= N; i++) {
		table[i][0] = -1;
		table[i][1] = -1;
	}
	ans = min(DFS(1, 1, 1), DFS(1, 1, 0));
	cout << ans;
	return 0;
}

int DFS(int node, int parent, int type) {
	if (table[node][type] != -1) return table[node][type];
	int A = 0, B = 0;
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] != parent) A += DFS(tree[node][i], node, 1);		
	}
	if(type == 1) {
		for (int i = 0; i < tree[node].size(); i++) {
			if (tree[node][i] != parent) B += min(DFS(tree[node][i], node, 0), DFS(tree[node][i], node, 1));
		}		
	}
	if (type == 0) table[node][type] = A;
	else table[node][type] = 1 + B;
	return table[node][type];
}