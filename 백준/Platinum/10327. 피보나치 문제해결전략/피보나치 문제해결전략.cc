#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 1000000000ll;

int N;
ll fibo[44];

ll GCD(ll a, ll b);
pii EEu(ll a, ll b);

void solve() {
	cin >> N;
	pii ans = { INF, INF };
	for (int i = 0; i < 43; i++) {
		ll a = fibo[i], b = fibo[i + 1];
		ll d = GCD(a, b);
		if (N % d) continue;
		pii st = EEu(a, b);
		ll x0 = st.first * N / d, y0 = st.second * N / d;
		ll k = ceil((double)-x0 / b);
		x0 += b * k;
		y0 -= a * k;
		if (x0 < 0 || y0 < 0) continue;
		if (x0 + y0 < ans.first + ans.second) ans = { x0,y0 };
	}
	if (ans.first == 0 || ans.first > ans.second) cout << ans.second << " " << ans.first + ans.second << "\n";
	else cout << ans.first << " " << ans.second << "\n";
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fibo[0] = 1;
	fibo[1] = 1;
	for (int i = 2; i < 44; i++) fibo[i] = fibo[i - 2] + fibo[i - 1];
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
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

pii EEu(ll a, ll b) {
	ll s0 = 1, s1 = 0, t0 = 0, t1 = 1, r0 = a, r1 = b, q;
	while (1) {
		q = r0 / r1;
		r0 %= r1; swap(r0, r1);
		if (r1 == 0) break;
		s0 -= q * s1; swap(s0, s1);
		t0 -= q * t1; swap(t0, t1);
		s0 %= b;
		t0 %= a;
	}
	return { s1,t1 };
}