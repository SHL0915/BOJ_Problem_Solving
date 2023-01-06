#include <bits/stdc++.h>
using namespace std;

int N, M;
vector <int> tree[50001];
int parent[50001][20];
int level[50001];

void pre(int node, int par, int lv);
int LCA(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	pre(1, 1, 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}

void pre(int node, int par, int lv) {
	level[node] = lv;
	parent[node][0] = par;
	for (int i = 1; i < 20; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (next == par) continue;
		pre(next, node, lv + 1);
	}
	return;
}

int LCA(int A, int B) {
	if (A == 1 || B == 1) return 1;
	if (level[A] < level[B]) swap(A, B);
	if (level[A] != level[B] ) {
		for (int i = 19; i >= 0; i--) {
			if (level[parent[A][i]] >= level[B]) A = parent[A][i];			
		}
	}
	int ret = A;
	if (A != B) {
		for (int i = 19; i >= 0; i--) {
			if (parent[A][i] != parent[B][i]) {
				A = parent[A][i];
				B = parent[B][i];
			}
			ret = parent[A][i];
		}
	}
	return ret;
}