#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100001];
int mark[100001];
int check[100001];

void DFS(int node, int start);

void solve() {
	cin >> N;
	memset(mark, 0, sizeof(mark));
	memset(check, 0, sizeof(check));
	for (int i = 1; i <= N; i++) cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		if (mark[i] == 0) DFS(i, i);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (check[i] == 0) ans++;
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

void DFS(int node, int start) {
	if (mark[node] && mark[node] != start) return;
	if (mark[node] == start && check[node] == 1) return;
	if (mark[node] == start) check[node] = 1;
	mark[node] = start;

	DFS(arr[node], start);
	return;
}