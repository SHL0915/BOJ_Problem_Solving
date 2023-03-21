#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, A, B, C, D;

void solve() {
	cin >> N >> A >> B >> C >> D;
	ll ans = 0;
	if (B * C > A * D) {
		swap(A, C);
		swap(B, D);
	}

	ans += (N / A) * B;	
	if (N % A) ans += B;

	for (ll i = 1; i <= N / C + 5; i++) {
		ll val = i * D;
		ll num = i * C;
		if (N > num) {
			val += (N - num) / A * B;
			if ((N - num) % A) val += B;
		}
		ans = min(ans, val);
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
	//cin >> t;
	while (t--) solve();
	return 0;
}