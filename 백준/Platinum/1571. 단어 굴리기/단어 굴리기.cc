#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
string str[51];
pii arr[51];
string S;

ll GCD(ll a, ll b);
ll LCM(ll a, ll b);
ll EEu(ll a, ll b);
pii CRT(pii a, pii b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> str[i];
	cin >> S;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < str[i].size(); j++) {
			if (str[i][j] == S[i]) arr[i] = { j, str[i].size() };
		}
		if (arr[i].second == 0) {
			cout << -1;
			return 0;
		}
	}
	pii ans = arr[0];
	for (int i = 1; i < N; i++) ans = CRT(ans, arr[i]);
	cout << ans.first;
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

ll LCM(ll a, ll b) {
	return a * b / GCD(a, b);
}

ll EEu(ll a, ll b) {
	ll s0 = 1, s1 = 0, t0 = 0, t1 = 1, r0 = a, r1 = b, q;
	while (1) {
		q = r0 / r1;
		r0 %= r1; swap(r0, r1);
		if (r1 == 0) break;
		s0 -= q * s1; swap(s0, s1); s0 %= b;
		t0 -= q * t1; swap(t0, t1); t0 %= a;
	}
	return s1;
}

pii CRT(pii a, pii b) {
	ll d1 = a.second, d2 = b.second, r1 = a.first, r2 = b.first;
	ll g = GCD(d1, d2), d = LCM(d1, d2), r, x1;
	if (r1 > r2) {
		swap(r1, r2);
		swap(d1, d2);
	}
	if ((r2 - r1) % g) {
		cout << -1;
		exit(0);
	}
	x1 = (EEu(d1 / g, d2 / g) + (d2 / g)) % (d2 / g);
	x1 *= (r2 - r1) / g;
	x1 %= d;
	r = ((x1 * d1) % d + r1) % d;
	return { r,d };
}