#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[101];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	int res = 0;
	for (int i = 0; i < N; i++) res ^= arr[i];
	if (res) cout << "koosaga";
	else cout << "cubelover";
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