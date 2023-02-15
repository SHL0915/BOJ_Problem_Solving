#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N;
int table[1000001];
vector <ll> primeNum;
deque <ll> primeFact;

void solve() {
	cin >> N;
	for (int i = 0; i < primeNum.size(); i++) {
		ll now = primeNum[i];
		if (now * now > N) break;
		if (N % now == 0) {
			while (1) {
				if (N % now) break;
				N /= now;
				primeFact.push_back(now);
			}
		}
	}
	if (N != 1) primeFact.push_back(N);

	if (primeFact.size() == 1) {
		cout << -1;
		return;
	}

	while (primeFact.size() >= 2) {
		if (primeFact.size() == 3) {
			cout << primeFact[0] * primeFact[1] * primeFact[2];
			break;
		}
		else {
			ll a = primeFact.front(); primeFact.pop_front();
			ll b = primeFact.front(); primeFact.pop_front();
			cout << a * b << " ";
		}
	}
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	for (ll i = 2; i <= 1000000; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			for (ll j = i * i; j <= 1000000; j += i) table[j] = 1;
		}
	}
	//cin >> t;
	while (t--) solve();
	return 0;
}