#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const int sz = 405;

int N;
vector <pii> up, down;
int dp[sz][sz][sz][2];

void solve() {
	cin >> N;
	ll now = 0;
	for (int i = 0; i < N; i++) {
		ll a, b; cin >> a >> b;
		if (b >= a) up.push_back({ a,b });
		else down.push_back({ b,a });
	}

	sort(up.begin(), up.end());
	for (int i = 0; i < up.size(); i++) {
		if (now < up[i].first) {
			cout << 0;
			return;
		}
		now -= up[i].first;
		now += up[i].second;
	}

	sort(down.begin(), down.end());

	ll l = 0, r = 1000000000LL;
	while (l <= r) {
		ll mid = (l + r) / 2;
		ll sum = mid;
		int flag = 0;
		for (int i = 0; i < down.size(); i++) {
			if (sum < down[i].first) {
				flag = 1;
				break;
			}
			sum -= down[i].first;
			sum += down[i].second;
		}

		if (flag == 1) l = mid + 1;
		else {
			if (sum <= now) {
				cout << 1;
				return;
			}
			r = mid - 1;
		}
	}

	cout << 0;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}