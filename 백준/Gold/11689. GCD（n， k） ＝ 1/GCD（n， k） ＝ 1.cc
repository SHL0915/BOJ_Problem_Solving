#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, ans;
int table[1000001];
vector <ll> primeNum;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (ll i = 2; i <= 1000000; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			for (ll j = i * i; j <= 1000000; j += i) table[j] = 1;
		}
	}
	cin >> N;
	ans = N;
	for (int i = 0; i < primeNum.size(); i++) {
		ll now = primeNum[i];
		if (now * now > N) break;
		if (N % now == 0) {
			ans /= now;
			ans *= (now - 1);
			while (1) {
				if (N % now) break;
				N /= now;
			}
		}
	}
	if (N != 1) {
		ans /= N;
		ans *= (N - 1);
	}
	cout << ans;
	return 0;
}