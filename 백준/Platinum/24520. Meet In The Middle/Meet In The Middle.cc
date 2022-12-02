#include <bits/stdc++.h>
using namespace std;

int N, K;
vector <pair<int, long long>> tree[100001];
map <pair<int, int>, long long> d;
int level[100001];
int parent[100001][21];
long long dist[100001][21];

void pre(int node, int par, int lv);
int LCA(int A, int B);
int find_middle(int A, int B, int lca);
long long find_distance(int A, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		tree[u].push_back({ v,w });
		tree[v].push_back({ u,w });
		d[{u, v}] = w;
		d[{v, u}] = w;
	}
	d[{1, 0}] = 0;
	pre(1, 0, 1);
	for (int i = 0; i < K; i++) {
		int u, v;
		cin >> u >> v;
		cout << find_middle(u, v, LCA(u, v)) << '\n';
	}
	return 0;
}

void pre(int node, int par, int lv) {
	level[node] = lv;
	parent[node][0] = par;
	dist[node][0] = d[{node, par}];
	for (int i = 1; i <= 20; i++) {
		parent[node][i] = parent[parent[node][i - 1]][i - 1];
		dist[node][i] = dist[node][i - 1] + dist[parent[node][i - 1]][i - 1];
	}
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

int find_middle(int A, int B, int lca) {
	long long dist_A = find_distance(A, level[A] - level[lca]);
	long long dist_B = find_distance(B, level[B] - level[lca]);
	if (dist_A == dist_B) return lca;
	if (dist_A < dist_B) {
		long long temp = A;
		A = B;
		B = temp;
		temp = dist_A;
		dist_A = dist_B;
		dist_B = temp;
	}	
	if ((dist_A - dist_B) % 2 == 1) return -1;
	long long len = dist_A - (dist_A - dist_B) / 2;
	long long temp = 0;
	for (int i = 20; i >= 0; i--) {
		if (temp + dist[A][i] <= len) {
			temp += dist[A][i];
			A = parent[A][i];
		}
	}
	if (temp == len) return A;
	else return -1;
}

long long find_distance(int A, int k) {
	long long ret = 0;
	int bit = 1;
	int cnt = 0;
	while (bit <= k) {
		if (bit & k) {
			ret += dist[A][cnt];
			A = parent[A][cnt];
		}
		cnt++;
		bit <<= 1;
	}
	return ret;
}