#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[16];

void solve() {
	cin >> N;
	arr[0] = 2;
	for (int i = 1; i <= N; i++) arr[i] = arr[i - 1] + (1LL << (i - 1));
	cout << arr[N] * arr[N];
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
