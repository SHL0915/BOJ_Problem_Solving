#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N;
string S;
ll E_sum[200005];
ll W_sum[200005];
ll pow_2[200005];

void solve() {
	cin >> N;
	cin >> S; S = '0' + S;
	for (int i = 1; i <= N; i++) {
		if (S[i] == 'E') E_sum[i]++;
		if (S[i] == 'W') W_sum[i]++;
		E_sum[i] += E_sum[i - 1];
		W_sum[i] += W_sum[i - 1];
	}

	ll ans = 0;

	for (int i = 1; i <= N; i++) {
		if (S[i] == 'H') {
			ll f = W_sum[i];
			ll b = E_sum[N] - E_sum[i];
			b = pow_2[b] - b - 1;
			b = (b + mod) % mod;

			ans += (f * b) % mod;
			ans %= mod;
		}
	}

	cout << ans;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	pow_2[0] = 1;
	for (int i = 1; i <= 200000; i++) pow_2[i] = (pow_2[i - 1] * 2) % mod;
	//cin >> t;
	while (t--) solve();
	return 0;
}