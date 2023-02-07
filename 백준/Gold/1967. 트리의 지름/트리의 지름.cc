#include <iostream>
#include <vector>
using namespace std;

int N, max_val, max_index;
vector <pair<int, int>> tree[10000];
int mark[10000];

void DFS(int node, int val);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v, val;
		cin >> u >> v >> val;
		tree[u - 1].push_back({ v - 1,val });
		tree[v - 1].push_back({ u - 1,val });
	}
	for (int i = 0; i < N; i++) mark[i] = -1;
	DFS(0, 0);
	max_val = -1;
	for (int i = 0; i < N; i++) {
		if (max_val <= mark[i]) {
			max_val = mark[i];
			max_index = i;
		}
	}
	for (int i = 0; i < N; i++) mark[i] = -1;
	DFS(max_index, 0);
	max_val = -1;
	for (int i = 0; i < N; i++) max_val = max(max_val, mark[i]);
	cout << max_val;
	return 0;
}

void DFS(int node, int val) {
	if (mark[node] != -1) return;
	mark[node] = val;
	for (int i = 0; i < tree[node].size(); i++) DFS(tree[node][i].first, val + tree[node][i].second);
	return;
}