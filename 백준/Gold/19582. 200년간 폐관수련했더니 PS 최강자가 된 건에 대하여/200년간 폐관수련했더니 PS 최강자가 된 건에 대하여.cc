#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
	cin >> N;
	ll sum = 0, M = 0, flag = 0;
	for (int i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;
		if (sum > a) {
			if (flag) {
				cout << "Zzz";
				return;
			}
			if (i == N - 1) continue;
			if (b > M) {	
				flag = 1;
				continue;
			}
			else {
				if (sum - M > a) {
					flag = 1;
					continue;
				}
				else {
					sum -= M;
					sum += b;
					flag = 1;
				}
			}			
		}
		else {
			sum += b;
			M = max(M, b);
		}
	}
	cout << "Kkeo-eok";
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