#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin >> N;
	ans = N;
	for (ll i = 2; i * i <= N; i++) {
		if (N % i == 0) {
			ans = ans / i * (i - 1);
			while (1) {
				if (N % i) break;
				N /= i;
			}
		}
	}
	if (N != 1) ans = ans / N * (N - 1);	
	cout << ans;
	return 0;
}