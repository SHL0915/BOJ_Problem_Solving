#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, K;
vector <int> tree[100001];
map <pair<int, int>, int> m;
int level[100001];
int parent[100001][21];
int min_val[100001][21];
int max_val[100001][21];

void findParent(int node, int par, int lv);
int LCA(int A, int B);
pair<int, int> find_min_max(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		tree[A].push_back(B);
		tree[B].push_back(A);
		m[{A, B}] = C;
		m[{B, A}] = C;
	}
	memset(min_val, INF, sizeof(min_val));
	m[{1, 0}] = 0;
	findParent(1, 0, 1);	
	cin >> K;
	for (int i = 0; i < K; i++) {
		pair<int, int> result;
		int A, B;
		cin >> A >> B;
		result = find_min_max(A, B);
		cout << result.first << " " << result.second << '\n';
	}
	return 0;
}

void findParent(int node, int par, int lv) {
	level[node] = lv;
	parent[node][0] = par;
	min_val[node][0] = m[{node, par}];
	max_val[node][0] = m[{node, par}];
	for (int i = 1; i <= 20; i++) {
		parent[node][i] = parent[parent[node][i - 1]][i - 1];
		min_val[node][i] = min(min_val[node][i], min_val[parent[node][i - 1]][i - 1]);
		min_val[node][i] = min(min_val[node][i - 1], min_val[node][i]);
		max_val[node][i] = max(max_val[node][i - 1], max_val[node][i]);
		max_val[node][i] = max(max_val[node][i], max_val[parent[node][i - 1]][i - 1]);
	}
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] == par) continue;
		findParent(tree[node][i], node, lv + 1);
	}
	return;
}

pair<int, int> find_min_max(int A, int B) {
	if (level[A] < level[B]) {
		int temp = A;
		A = B;
		B = temp;
	}
	int min_ret = INF;
	int max_ret = 0;
	if (level[A] != level[B]) {
		for (int i = 20; i >= 0; i--) {
			if (level[parent[A][i]] >= level[B]) {
				min_ret = min(min_ret, min_val[A][i]);
				max_ret = max(max_ret, max_val[A][i]);
				A = parent[A][i];
			}
		}
	}
	if (A != B) {
		for (int i = 20; i >= 0; i--) {
			if (parent[A][i] != parent[B][i]) {
				min_ret = min(min_ret, min_val[A][i]);
				min_ret = min(min_ret, min_val[B][i]);
				max_ret = max(max_ret, max_val[A][i]);
				max_ret = max(max_ret, max_val[B][i]);
				A = parent[A][i];
				B = parent[B][i];
			}
		}
		min_ret = min(min_ret, min_val[A][0]);
		min_ret = min(min_ret, min_val[B][0]);
		max_ret = max(max_ret, max_val[A][0]);
		max_ret = max(max_ret, max_val[B][0]);
	}
	pair<int, int> ret = { min_ret, max_ret };
	return ret;
}