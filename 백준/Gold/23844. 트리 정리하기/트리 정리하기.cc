#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K, max_lev, ans;
vector <int> tree[10001];
vector <int> level[10001];

void DFS(int node, int parent, int lev);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		int A, B;
		cin >> A >> B;
		tree[A].push_back(B);
		tree[B].push_back(A);
	}
	DFS(1, -1, 0);
	for (int i = max_lev; i >= 0; i--) ans += min(K, (int)level[i].size());
	cout << ans;
	return 0;
}

void DFS(int node, int parent, int lev) {
	max_lev = max(max_lev, lev);
	level[lev].push_back(node);
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] != parent) DFS(tree[node][i], node, lev + 1);		
	}
	return;
}