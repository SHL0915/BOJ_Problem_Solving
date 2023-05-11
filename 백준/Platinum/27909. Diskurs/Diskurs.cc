#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[(1 << 21)];
int mark[(1 << 21)];
queue <pii> q;

void BFS();

void solve() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		q.push({ arr[i], 0 });
	}

	memset(mark, -1, sizeof(mark));
	while (q.size()) BFS();

	for (int i = 0; i < N; i++) cout << M - mark[(1 << M) - 1 - arr[i]] << " ";

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

void BFS() {
	pii f = q.front(); q.pop();
	int now = f.first;
	int d = f.second;
	if (mark[now] != -1) return;
	mark[now] = d;
	for (int i = 0; i < M; i++) q.push({ now ^ (1 << i), d + 1 });
	return;
}