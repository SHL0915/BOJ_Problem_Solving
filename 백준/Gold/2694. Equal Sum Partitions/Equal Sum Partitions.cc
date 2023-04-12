#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[10001];

void solve() {
	cin >> N;
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	ll ans = sum;

	for (ll i = 1; i * i <= sum; i++) {
		if (sum % i == 0) {
			ll a = i, b = sum / i;
			ll now = 0, flag = 0;
			for (int j = 0; j < N; j++) {
				now += arr[j];

				if (now > a) {
					flag = 1;
					break;
				}
				else if (now == a) now = 0;
				else continue;
			}

			if (flag == 0) ans = min(ans, a);
			now = 0; flag = 0;

			for (int j = 0; j < N; j++) {
				now += arr[j];

				if (now > b) {
					flag = 1;
					break;
				}
				else if (now == b) now = 0;
				else continue;
			}

			if (flag == 0) ans = min(ans, b);
		}
	}

	cout << ans << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}