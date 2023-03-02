#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, A;
pair<ll, pii> arr[123456];

ll BinarySearch(ll left, ll right);

void solve() {
	cin >> N >> A;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;

	ll ans = BinarySearch(1LL, 9000000000000000000LL);

	ll damage = A, health = ans;
	int flag = 0;
	for (int i = 0; i < N; i++) {
		ll t = arr[i].first, a = arr[i].second.first, h = arr[i].second.second;
		if (t == 1) {
			ll cnt = h / damage;
			if (h % damage) cnt++;
			health -= a * (cnt - 1);
			if (health <= 0) {
				flag = 1;
				break;
			}
		}
		else {
			damage += a;
			health += h;
			health = min(health, ans);
		}
	}

	if (flag) ans++;

	cout << ans;
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

ll BinarySearch(ll left, ll right) {
	if (left < right) {
		ll mid = (left + right) / 2;
		ll damage = A, health = mid;
		int flag = 0;
		for (int i = 0; i < N; i++) {
			ll t = arr[i].first, a = arr[i].second.first, h = arr[i].second.second;
			if (t == 1) {
				ll cnt = h / damage;
				if (h % damage) cnt++;
				health -= a * (cnt - 1);
				if (health <= 0) {
					flag = 1;
					break;
				}
			}
			else {
				damage += a;
				health += h;
				health = min(health, mid);
			}
		}	

		if (flag) return BinarySearch(mid + 1, right);
		else return BinarySearch(left, mid - 1);
	}
	else return left;
}