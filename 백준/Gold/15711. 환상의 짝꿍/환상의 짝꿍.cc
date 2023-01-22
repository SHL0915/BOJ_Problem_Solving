#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll A, B;
int table[10000001];
vector <ll> primeNum;

void solve() {
	cin >> A >> B;
	if (A + B == 2 || A + B == 3) {
		cout << "NO\n";
		return;
	}
	if ((A + B) % 2 == 0) {
		cout << "YES\n";
		return;
	}
	else {
		ll temp = A + B - 2;		
		for (int i = 0; i < primeNum.size(); i++) {
			ll now = primeNum[i];
			if (now * now > temp) break;
			if (temp % now == 0) {
				while (1) {
					if (temp % now) break;
					temp /= now;
				}
			}
		}
		if (temp == A + B - 2) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (ll i = 2; i <= 10000000; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			for (ll j = i * i; j <= 10000000; j += i) table[j] = 1;
		}
	}
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}