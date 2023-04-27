#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, K, SZ;
int arr[21];
int table[1000005];

int DP(int now);

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	int G = arr[N - 1];
	SZ = G * G;

	int ans;
	memset(table, -1, sizeof(table));
	if (K <= SZ) ans = DP(K);
	else ans = DP(SZ - K % SZ);

	if (ans) cout << "possible";
	else cout << "impossible";

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

int DP(int now) {
	if (now < 0) return 0;
	if (now == 0) return 1;
	int& ret = table[now];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < N; i++) ret |= DP(now - arr[i]);
	return ret;
}