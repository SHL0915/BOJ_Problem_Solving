#include <bits/stdc++.h>
using namespace std;

int N, M;
vector <pair<int, int>> tree[40001];
int level[40001];
int parent[40001][20];
int mark[40001];

void DFS(int node, int par, int val);
void pre(int node, int par, int lv);
int LCA(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		tree[A].push_back({ B,C });
		tree[B].push_back({ A,C });
	}
	DFS(1, 0, 0);
	pre(1, 0, 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		cout << mark[A] + mark[B] - 2 * mark[LCA(A, B)] << '\n';
	}
	return 0;
}

void DFS(int node, int par, int val) {
	mark[node] = mark[par] + val;
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i].first == par) continue;
		DFS(tree[node][i].first, node, tree[node][i].second);
	}
	return;
}

void pre(int node, int par, int lv) {
	level[node] = lv;
	parent[node][0] = par;
	for (int i = 1; i < 20; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i].first == par) continue;
		pre(tree[node][i].first, node, lv + 1);
	}
	return;
}

int LCA(int A, int B) {
	if (A == 1 || B == 1) return 1;
	if (level[A] < level[B]) {
		int temp = A;
		A = B;
		B = temp;
	}
	if (level[A] != level[B]) {
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