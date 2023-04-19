#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, X, Y;
int arr[10001][101];
int process[101];

void solve() {
	cin >> N >> M >> X >> Y;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < X; j++) cin >> arr[i][j];
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < X; j++) {
			int a; cin >> a;
			process[j] = max(process[j], a);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < X; j++) {
			cout << min(arr[i][j], Y - process[j]) << " ";
		}
		cout << '\n';
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