#include <iostream>
#include <vector>
using namespace std;

int N;
vector <int> tree[10001];
int people[10001];
int table[10001][2];

int DFS(int node, int parent, int type);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> people[i];
	for (int i = 0; i < N - 1; i++) {
		int A, B;
		cin >> A >> B;
		tree[A].push_back(B);
		tree[B].push_back(A);
	}
	for (int i = 1; i <= N; i++) {
		table[i][0] = -1;
		table[i][1] = -1;
	}
	cout << max(DFS(1, 1, 0), DFS(1, 1, 1));
	return 0;
}

int DFS(int node, int parent, int type) {
	if (table[node][type] != -1) return table[node][type];
	if (type == 1) {
		table[node][type] = people[node];
		for (int i = 0; i < tree[node].size(); i++) {
			if (tree[node][i] != parent) table[node][type] += DFS(tree[node][i], node, 0);
		}
		return table[node][type];
	}
	else {
		table[node][type] = 0;
		for (int i = 0; i < tree[node].size(); i++) {
			if (tree[node][i] != parent) table[node][type] += max(DFS(tree[node][i], node, 0), DFS(tree[node][i], node, 1));
		}
		return table[node][type];
	}
}