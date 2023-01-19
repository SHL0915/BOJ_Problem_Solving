#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll A, B;

ll GCD(ll a, ll b);
ll LCM(ll a, ll b);

void solve() {
	cin >> A >> B;
	cout << LCM(A, B) << '\n';
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