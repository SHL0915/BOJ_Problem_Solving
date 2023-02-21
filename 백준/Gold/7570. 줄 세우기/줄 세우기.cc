#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, ans;
int arr[1000001];
int table[1000001];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) {
		int now = arr[i];
		table[now] = max(1, table[now - 1] + 1);
		ans = max(ans, table[now]);
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