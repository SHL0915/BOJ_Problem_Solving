#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q, M, cnt;
int arr[300001];
int in_degree[300001];

void solve() {
	cin >> N >> Q;
	cout << N << " " << Q << '\n';
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (arr[i] != i) cnt++;		
		in_degree[arr[i]]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		cout << 2 << " " << a << '\n';
	}

	for (int i = 0; i < Q - M - cnt; i++) cout << 1 << " " << 1 << " " << 1 << '\n';

	queue <int> q;
	
	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) q.push(i);
	}

	while (q.size()) {
		int f = q.front(); q.pop();
		cout << 1 << " " << f << " " << arr[f] << '\n';
		if (--in_degree[arr[f]] == 0) q.push(arr[f]);
	}
		
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