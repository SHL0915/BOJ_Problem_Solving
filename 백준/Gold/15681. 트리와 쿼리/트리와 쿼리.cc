#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector <int> tree[100001];
int cnt[100001];
int mark[100001];

int DFS(int vertex);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	cnt[R] = DFS(R);
	for (int i = 0; i < Q; i++) {
		int A;
		cin >> A;
		cout << cnt[A] << '\n';
	}
	return 0;
}

int DFS(int vertex) {
	if (mark[vertex] != 0) return 0;
	mark[vertex] = 1;
	int ret = 1;
	for (int i = 0; i < tree[vertex].size(); i++) ret += DFS(tree[vertex][i]);
	cnt[vertex] = ret;
	return ret;
}