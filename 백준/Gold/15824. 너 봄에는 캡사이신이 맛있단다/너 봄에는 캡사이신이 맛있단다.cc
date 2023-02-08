#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N;
int arr[300001];
ll psum[300001];
ll p[300001];

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];	
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++) psum[i] = (psum[i - 1] + arr[i]) % mod;
	ll ans = 0;
	for (int i = N - 1; i >= 1; i--) {
		ll l = N - i, r = N - l;
		ans = (ans + (psum[N] - (psum[r] + psum[l]) % mod) * p[i - 1] % mod) % mod;
	}
	cout << (ans + mod) % mod;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	p[0] = 1;
	for (int i = 1; i <= 300000; i++) p[i] = (p[i - 1] * 2) % mod;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}