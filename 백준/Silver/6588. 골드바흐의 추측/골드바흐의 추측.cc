#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int table[2000001];
vector <int> primeNum;

void solve() {
	while (1) {
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < primeNum.size(); i++) {
			if (table[N - primeNum[i]]) continue;
			else {
				cout << N << " = " << primeNum[i] << " + " << N - primeNum[i] << '\n';
				break;
			}
		}
	}	
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
	//cin >> t;
	while (t--) solve();
	return 0;
}