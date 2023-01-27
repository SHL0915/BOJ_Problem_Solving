#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll L, len, damage, C;
int psum[3000001];

void solve() {
	cin >> L >> len >> damage >> C;
	for (int i = 1; i <= L; i++) {
		int a; cin >> a;
		ll now = (psum[i - 1] - psum[max(0LL, i - len)]) * damage;
		if (a > now + damage) {
			if (C) C--;
			else {
				cout << "NO";
				return;
			}
		}
		else psum[i] = 1;
		psum[i] += psum[i - 1];
	}
	cout << "YES";
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