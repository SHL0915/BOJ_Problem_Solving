#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int table[10001];
vector <int> primeNum;

void solve() {
	cin >> N;
	for (int i = 0; i < primeNum.size(); i++) {
		int now = primeNum[i];
		if (now > N) break;
		if (N % now == 0) {
			while (1) {
				if (N % now) break;
				cout << now << '\n';
				N /= now;
			}
		}
	}
	if (N != 1) cout << N;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i <= 10000; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			for (int j = i * i; j <= 10000; j += i) table[j] = 1;
		}
	}
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}