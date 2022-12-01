#include <bits/stdc++.h>
using namespace std;

int N, M;
vector <int> tree[100001];
int parent[100001][20];
int level[100001];

void pre(int node, int par, int lv);
int LCA(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int A, B;
		cin >> A >> B;
		tree[A].push_back(B);
		tree[B].push_back(A);
	}
	pre(1, 0, 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		cout << LCA(A, B) << '\n';
	}
	return 0;
}

void pre(int node, int par, int lv) {
	level[node] = lv;
	parent[node][0] = par;
	for (int i = 1; i < 20; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] == par) continue;
		pre(tree[node][i], node, lv + 1);
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
			if (level[parent[A][i]] >= level[B]) {
				A = parent[A][i];
			}
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