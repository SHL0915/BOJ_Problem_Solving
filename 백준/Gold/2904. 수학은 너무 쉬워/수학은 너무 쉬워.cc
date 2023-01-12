#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
ll cnt[1000001], table[1000001];
vector <ll> arr[1000001];
vector <ll> primeNum;

ll pow(ll a, ll b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (ll i = 2; i * i <= 1000000; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			for (long long j = i * i; j <= 1000000; j += i) table[j] = 1;
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector <pair<ll, ll>> v;
		ll a;
		cin >> a;
		for (int j = 0; j < primeNum.size(); j++) {
			ll now = primeNum[j];
			if (now > a) break;
			if (a % now == 0) {
				v.push_back({ now,0 });
				while (1) {
					if (a % now) break;
					a /= now;
					v.back().second++;
				}
			}
		}
		if (a != 1) v.push_back({ a,1 });
		for (int j = 0; j < v.size(); j++) {
			cnt[v[j].first] += v[j].second;
			arr[v[j].first].push_back(v[j].second);
		}
	}
	ll ans = 1, c = 0;
	for (int i = 0; i < 1000001; i++) {
		ll mul = (cnt[i] / N);
		if (mul) {			
			ans *= pow(i, mul);
			c += mul * (N - arr[i].size());
			for (int j = 0; j < arr[i].size(); j++) {
				if (arr[i][j] >= mul) continue;
				else c += mul - arr[i][j];
			}
		}
	}
	cout << ans << " " << c;
	return 0;
}

ll pow(ll a, ll b) {
	ll ret = 1;
	for (int i = 0; i < b; i++) ret *= a;
	return ret;
}