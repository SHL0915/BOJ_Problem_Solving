#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int mod = 1000000007;

int N, M, C, cnt;
int arr[200001];
pii ETT[200001];
int id[200001];
vector <int> graph[200001];
vector <vector<int>> tree;

void DFS(int node, int par);
void build(int node, int start, int end);
int query(int node, int start, int end, int left, int right, int k);

void solve() {
	cin >> N >> M >> C;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(1, -1);
	tree.resize(4 * N);
	build(1, 1, N);
	ll ans = 0;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ans = (ans + query(1, 1, N, ETT[a].first, ETT[a].second, b)) % mod;
	}
	cout << ans;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void DFS(int node, int par) {
	cnt++;
	ETT[node].first = cnt;
	id[cnt] = node;
	for (int i = 0; i < graph[node].size(); i++) {
		if (graph[node][i] == par) continue;
		DFS(graph[node][i], node);
	}
	ETT[node].second = cnt;
	return;
}

void build(int node, int start, int end) {
	if (start == end) {
		tree[node].push_back(arr[id[start]]);
		return;
	}
	int mid = (start + end) / 2;
	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);
	vector <int>& l = tree[node * 2], &r = tree[node * 2 + 1];
	tree[node].resize(l.size() + r.size());
	merge(l.begin(), l.end(), r.begin(), r.end(), tree[node].begin());
	return;
}

int query(int node, int start, int end, int left, int right, int k) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return (upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin());
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right, k) + query(node * 2 + 1, mid + 1, end, left, right, k);
}