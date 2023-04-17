#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, ans;
vector <int> graph[1001];
int mark[1001];
int A[1001], B[1001];

int DFS(int node);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			graph[i].push_back(a);
		}
	}

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	for (int i = 0; i < N; i++) {
		if (A[i] == -1) {
			memset(mark, 0, sizeof(mark));
			ans += DFS(i);
		}
	}

	cout << N - ans;
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
		if (B[now] == -1) {
			B[now] = node;
			A[node] = now;
			return 1;
		}
	}
    
	for (int i = 0; i < graph[node].size(); i++) {
		int now = graph[node][i];
		if (mark[B[now]] == 0 && DFS(B[now])) {
			B[now] = node;
			A[node] = now;
			return 1;
		}
	}
	return 0;
}