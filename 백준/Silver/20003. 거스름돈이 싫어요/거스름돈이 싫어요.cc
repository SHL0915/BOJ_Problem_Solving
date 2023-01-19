#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[51];

ll GCD(ll a, ll b);
ll LCM(ll a, ll b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		arr[i].first = a / GCD(a, b);
		arr[i].second = b / GCD(a, b);
	}
	ll a = arr[0].first, b = arr[0].second;
	for (int i = 1; i < N; i++) {
		a = GCD(a, arr[i].first);
		b = LCM(b, arr[i].second);
	}
	cout << a / GCD(a, b) << " " << b / GCD(a, b) << '\n';
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