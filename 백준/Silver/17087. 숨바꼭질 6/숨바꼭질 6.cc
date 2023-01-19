#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, S;
ll arr[100001];
ll delt[100001];

ll absol(ll a);
ll GCD(ll a, ll b);

void solve() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		delt[i] = absol(arr[i] - S);
	}
	ll ans = delt[0];
	for (int i = 1; i < N; i++) ans = GCD(ans, delt[i]);
	cout << ans << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

ll absol(ll a) {
	if (a < 0) return -a;
	else return a;
}

ll GCD(ll a, ll b) {
	if (a > b) {
		if (a % b) return GCD(a % b, b);
		else return b;
	}
	else {
		if (b % a) return GCD(b % a, a);
		else return a;
	}
}