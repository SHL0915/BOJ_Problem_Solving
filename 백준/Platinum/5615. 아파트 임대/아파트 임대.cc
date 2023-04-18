#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;

int N;
ll arr[100001];
vector <ll> check;

ll power(ll a, ll k, ll mod);
int miller(ll n, ll a);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	int cnt = 0;

	check.push_back(2);
	check.push_back(7);
	check.push_back(61);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < check.size(); j++) {
			if (miller(2 * arr[i] + 1, check[j]) == 0) {
				cnt++;
				break;
			}
		}
	}

	cout << N - cnt;
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

ll power(ll a, ll k, ll mod) {
	ll ret = 1;
	a %= mod;
	while (k) {
		if (k & 1) ret = (ret * a) % mod;
		a = (a * a) % mod;
		k /= 2;
	}
	return ret;
}

int miller(ll n, ll a) {
	if (a % n == 0) return 1;
	ll k = n - 1;
	while (1) {
		ll temp = power(a, k, n);
		if (temp == n - 1) return 1;
		if (k % 2) return (temp == 1 || temp == n - 1);
		k /= 2;
	}
}