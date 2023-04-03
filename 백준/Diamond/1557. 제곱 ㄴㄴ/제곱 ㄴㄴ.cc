#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 2 * 0x3f3f3f3f;

int K;
int mobius[1000001];
int sieve[1000001];
vector <ll> primeNum;

void solve() {
	cin >> K;
	for (ll i = 2; i * i <= INF; i++) {
		if (sieve[i] == 0) {
			primeNum.push_back(i);
			for (ll j = i * i; j * j <= INF; j += i) sieve[j] = 1;
		}
	}

	for (ll i = 2; i * i <= INF; i++) {
		ll now = i, flag = 0;
		vector <int> v;
		for (int j = 0; j < primeNum.size(); j++) {
			ll p = primeNum[j];
			if (p * p > now) break;
			if (now % p == 0) {
				v.push_back(p);
				int cnt = 0;
				while (1) {
					if (now % p) break;
					else {
						now /= p;
						cnt++;
					}
				}
				if (cnt >= 2) {
					flag = 1;
					break;
				}
			}
		}
		if (flag) continue;
		if (v.size() % 2) mobius[i] = -1;
		else mobius[i] = 1;
	}

	ll l = 0, r = INF;

	while (l < r) {
		ll cnt = 0, mid = (l + r) / 2;
		for (ll i = 2; i * i <= mid; i++) cnt += mobius[i] * (mid / (i * i));
		cnt = mid - cnt;

		if (cnt >= K) r = mid - 1;		
		else l = mid + 1;
	}

	ll cnt = 0;
	for (ll i = 2; i * i <= r; i++) cnt += mobius[i] * (r / (i * i));
	cnt = r - cnt;
	if (cnt < K) r++;

	cout << r;
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