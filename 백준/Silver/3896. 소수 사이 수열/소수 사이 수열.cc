#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int table[2000001];
vector <int> primeNum;

void solve() {
	cin >> N;
	int idx = lower_bound(primeNum.begin(), primeNum.end(), N) - primeNum.begin();
	if (primeNum[idx] == N) cout << 0 << '\n';
	else cout << primeNum[idx] - primeNum[idx - 1] << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (ll i = 2; i <= 2000000; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			for (ll j = i * i; j <= 2000000; j += i) table[j] = 1;
		}
	}
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}