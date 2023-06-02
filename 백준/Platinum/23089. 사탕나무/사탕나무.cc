#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
vector <int> tree[100005];
int psum[100005][45];
int parent[100005];

void DFS(int node, int par);
int reverse(int node, int child, int k);

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1, 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 2 * K; j++) psum[i][j] += psum[i][j - 1];
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, psum[i][K] + reverse(parent[i], i, K - 1));
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
	psum[node][0] = 1;
	parent[node] = par;
	for (int next : tree[node]) {
		if (next == par) continue;
		DFS(next, node);
		for (int k = 1; k <= 2 * K; k++) {
			psum[node][k] += psum[next][k - 1];
		}
	}

	return;
}

int reverse(int node, int child, int k) {
	if (node == child) return 0;
	if (k == 0) return 1;	
	int ret = 0;

	ret += psum[node][k];
	ret -= psum[child][k - 1];

	ret += reverse(parent[node], node, k - 1);

	return ret;
}