#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int A[1001], B[1001], mark[1001];
vector <int> graph[1001];

int DFS(int node);

void solve() {
	cin >> N >> M;
	for (int i = 0; i <= 1000; i++) graph[i].clear();
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j <= b; j++) graph[i].push_back(j);
	}
	int ans = 0;
	for (int i = 0; i < M; i++) {
		if (A[i] == -1) {
			memset(mark, 0, sizeof(mark));
			ans += DFS(i);
		}
	}
	cout << ans << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
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