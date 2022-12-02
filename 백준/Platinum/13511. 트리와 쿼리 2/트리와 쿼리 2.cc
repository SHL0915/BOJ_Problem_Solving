#include <bits/stdc++.h>
using namespace std;

int N, M;
vector <pair<int, int>> tree[100001];
int level[100001];
int parent[100001][21];
long long mark[100001];

void DFS(int node, int par, long long val);
void pre(int node, int par, int lv);
int LCA(int A, int B);
int findParent(int node, int k);

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
		int A, B, C, K;
		cin >> A >> B >> C;
		if (A == 1) cout << mark[B] + mark[C] - 2 * mark[LCA(B, C)] << '\n';
		else {
			cin >> K;
			int lca = LCA(B, C);
			if (K <= level[B] - level[lca] + 1) cout << findParent(B, K - 1) << '\n';
			else {
				K -= (level[B] - level[lca] + 1);
				K = level[C] - level[lca] - K;
				cout << findParent(C, K) << '\n';
			}
		}
	}
	return 0;
}

void DFS(int node, int par, long long val) {
	mark[node] = val;
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i].first == par) continue;
		DFS(tree[node][i].first, node, val + tree[node][i].second);
	}
}

void pre(int node, int par, int lv) {
	level[node] = lv;
	parent[node][0] = par;
	for (int i = 1; i <= 20; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i].first == par) continue;
		pre(tree[node][i].first, node, lv + 1);
	}
}

int LCA(int A, int B) {
	if (A == 1 || B == 1) return 1;
	if (level[A] < level[B]) {
		int temp = A;
		A = B;
		B = temp;
	}
	if (level[A] != level[B]) {
		for (int i = 20; i >= 0; i--) {
			if (level[parent[A][i]] >= level[B]) A = parent[A][i];
		}
	}
	int ret = A;
	if (A != B) {
		for (int i = 20; i >= 0; i--) {
			if (parent[A][i] != parent[B][i]) {
				A = parent[A][i];
				B = parent[B][i];
			}
			ret = parent[A][i];
		}
	}
	return ret;
}

int findParent(int node, int k) {
	int bit = 1;
	int cnt = 0;
	while (bit <= k) {
		if (bit & k) node = parent[node][cnt];
		bit <<= 1;
		cnt++;
	}
	return node;
}