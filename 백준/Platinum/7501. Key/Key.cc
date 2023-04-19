#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;

ll A, B;
int sieve[100];
vector <ll> check;

ll power(ll a, ll k, ll mod);
int miller(ll n, ll a);

void solve() {
	cin >> A >> B;
	for (ll i = A; i <= B; i++) {
		if (i % 2 == 0) continue;

		int flag = 0;
		for (int j = 0; j < check.size(); j++) {
			if (miller(i, check[j]) == 0) flag = 1;			
		}

		if (flag == 0 || i == 9) cout << i << " ";
	}
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i <= 37; i++) {
		if (sieve[i] == 0) {
			check.push_back(i);
			for (int j = i * i; j <= 37; j += i) sieve[j] = 1;
		}
	}

	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

ll power(ll a, ll k, ll mod) {
	ll ret = 1;
	a %= mod;
	while (k) {
		if (k & 1) ret = ((__int128)ret * (__int128)a) % mod;
		a = ((__int128)a * (__int128)a) % mod;
		k >>= 1;
	}
	return ret;
}

int miller(ll n, ll a) {
	if (a % n == 0) return 1;
	ll k = n - 1;
	while (1) {
		ll temp = power(a, k, n);
		if (temp == n - 1) return 1;
		else {
			if (k % 2) return (temp == 1);
			k >>= 1;
		}
	}
}