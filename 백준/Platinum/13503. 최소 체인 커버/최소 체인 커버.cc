#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector <int> graph[10005];
int A[10005], B[10005], mark[10005];

int DFS(int node);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	int ans = N;

	for (int i = 1; i <= N; i++) {
		if (A[i] == 0) {
			memset(mark, 0, sizeof(mark));
			ans -= DFS(i);
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
	for (int next : graph[node]) {
		if (B[next] == 0 || mark[B[next]] == 0 && DFS(B[next])) {
			A[node] = next;
			B[next] = node;
			return 1;
		}
	}
	return 0;
}