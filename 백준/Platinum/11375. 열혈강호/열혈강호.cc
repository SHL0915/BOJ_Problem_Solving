#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector <int> graph[1001];
int A[1001], B[1001], mark[1001];

int DFS(int node);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			graph[i].push_back(a);
		}
	}
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (A[i] == -1) {
			memset(mark, 0, sizeof(mark));
			ans += DFS(i);
		}
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

int DFS(int node) {
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int now = graph[node][i];
		if (B[now] == -1 || mark[B[now]] == 0 && DFS(B[now])) {
			B[now] = node;
			A[node] = now;
			return 1;
		}
	}
	return 0;
}