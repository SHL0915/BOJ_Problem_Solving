#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll M, ans;

ll Probablity(ll S, ll N);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M;
	for (int i = 0; i < M; i++) {
		ll N, S;
		cin >> N >> S;
		ans = (ans + Probablity(S, N)) % mod;
	}
	cout << ans;
	return 0;
}

ll Probablity(ll S, ll N) {
	ll bit = 1;
	ll p = mod - 2;
	ll temp = N;
	ll result = 1;
	while (bit <= p) {
		if (bit & p) result = (result * temp) % mod;
		temp = (temp * temp) % mod;
		bit <<= 1;
	}
	result = (result * S) % mod;
	return result;
}