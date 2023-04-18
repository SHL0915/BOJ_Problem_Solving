#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll SZ = 1000000000;

ll N, P;
int sieve[100001];
vector <int> primeNum;
vector <pii> arr;

void check(ll now, int idx, int cnt);

void solve() {
	cin >> N >> P;

	if (P * P > SZ) {
		if (N == 1) cout << P;
		else cout << 0;
		return;
	}

	arr.push_back({ P,1 });
	check(P, 0, 0);
	
	ll l = P, r = SZ + 1;
	while (l < r) {
		ll mid = (l + r) / 2;
		ll cnt = 0;
		for (int i = 0; i < arr.size(); i++) cnt += (mid / arr[i].first) * arr[i].second;
		
		if (cnt >= N) r = mid;
		else l = mid + 1;
	}

	if (l > SZ) cout << 0;
	else cout << l;

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (ll i = 2; i * i <= 1000000005; i++) {
		if (sieve[i] == 0) {
			primeNum.push_back(i);
			for (ll j = i * i; j * j <= 1000000005; j += i) sieve[j] = 1;
		}
	}

	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}


void check(ll a, int idx, int cnt) {
	if (primeNum[idx] == P) return;
	check(a, idx + 1, cnt);

	ll next = a * primeNum[idx];
	if (next > SZ) return;
	cnt++;
	if (cnt % 2) arr.push_back({ next, -1 });
	else arr.push_back({ next, 1 });
	check(next, idx + 1, cnt);
	return;
}