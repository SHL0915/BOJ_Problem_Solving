#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N;
int arr[100001];
vector <pii> tree[100001];
int parent[100001][20];
int val[100001][20];

void pre(int node, int par, int lv, int v);
int query(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}
	pre(1, 1, 1, 0);
	for (int i = 1; i <= N; i++) cout << query(i) << '\n';
	return 0;
}

void pre(int node, int par, int lv, int v) {
	parent[node][0] = par;
	val[node][0] = v;
	for (int i = 1; i < 20; i++) {
		parent[node][i] = parent[parent[node][i - 1]][i - 1];
		val[node][i] = val[node][i - 1] + val[parent[node][i - 1]][i - 1];
	}
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i].first;
		int next_val = tree[node][i].second;
		if (next == par) continue;
		pre(next, node, lv + 1, next_val);
	}
	return;
}

int query(int node) {
	int now = arr[node];
	for (int i = 19; i >= 0; i--) {
		if (val[node][i] <= now) {
			now -= val[node][i];
			node = parent[node][i];
		}
	}
	return node;
}