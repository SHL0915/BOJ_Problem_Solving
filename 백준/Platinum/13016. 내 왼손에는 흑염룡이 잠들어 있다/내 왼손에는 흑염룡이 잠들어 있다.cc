#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, A, B;
vector <pii> tree[50001];
int arr[50001];
int distA[50001];
int distB[50001];

void DFS(int node, int par, int type);

void solve() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}

	DFS(1, -1, 0);

	int val = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] > val) {
			A = i;
			val = arr[i];
		}
	}

	DFS(A, -1, 1);

	val = 0;
	for (int i = 1; i <= N; i++) {
		if (distA[i] > val) {
			B = i;
			val = distA[i];
		}
	}

	DFS(B, -1, 2);

	for (int i = 1; i <= N; i++) cout << max(distA[i], distB[i]) << '\n';	
	
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

void DFS(int node, int par, int type) {
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i].first;
		if (next == par) continue;		
		switch (type) {
		case 0: arr[next] = arr[node] + tree[node][i].second; break;
		case 1: distA[next] = distA[node] + tree[node][i].second; break;
		case 2: distB[next] = distB[node] + tree[node][i].second; break;
		}
		DFS(next, node, type);
	}
	return;
}