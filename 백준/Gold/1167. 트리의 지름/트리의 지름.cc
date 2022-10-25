#include <iostream>
#include <vector>
using namespace std;

int V, max_len = -1, max_node;
vector <pair <int, int>> tree[100000];
int mark[100000];

void DFS(int node, int len);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V;
	for (int i = 0; i < V; i++) {
		int node;
		cin >> node;
		while (1) {
			int input, len;
			cin >> input;
			if (input == -1) break;
			cin >> len;
			tree[node - 1].push_back({ input - 1, len });
		}
	}
	for (int i = 0; i < V; i++) mark[i] = -1;
	DFS(0, 0);
	for (int i = 0; i < V; i++) {
		if (mark[i] >= max_len) {
			max_len = mark[i];
			max_node = i;
		}
	}
	for (int i = 0; i < V; i++) mark[i] = -1;
	DFS(max_node, 0);
	max_len = -1;
	for (int i = 0; i < V; i++) max_len = max(max_len, mark[i]);
	cout << max_len;
	return 0;
}

void DFS(int node, int len) {
	if (mark[node] != -1) return;
	mark[node] = len;
	for (int i = 0; i < tree[node].size(); i++) {
		DFS(tree[node][i].first, len + tree[node][i].second);
	}
}
