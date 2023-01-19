#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int M, N;
int table[1000001];
vector <int> primeNum;

void solve() {
	cin >> M >> N;
	for (ll i = 2; i <= N; i++) {
		if (table[i] == 0) {
			if (i >= M) primeNum.push_back(i);
			for (ll j = i * i; j <= N; j += i) table[j] = 1;
		}
	}
	for (int i = 0; i < primeNum.size(); i++) cout << primeNum[i] << '\n';
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