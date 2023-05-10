#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[200005];
ll ccw(pii a, pii b, pii c);
ll ccw2(pii a, pii b);
pii sub(pii a, pii b);
ll sqrdist(pii a, pii b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	sort(arr + 1, arr + N, [&](pii a, pii b) {
		ll res = ccw(arr[0], a, b);
		if (res) return res > 0;
		else return a < b;
		});

	vector <pii> ans;
	ans.push_back(arr[0]); ans.push_back(arr[1]);
	for (int i = 2; i < N; i++) {
		pii c = arr[i];
		while (ans.size() >= 2) {
			pii b = ans.back(); ans.pop_back();
			pii a = ans.back();
			if (ccw(a, b, c) > 0) {
				ans.push_back(b);
				break;
			}
		}
		ans.push_back(c);
	}

	int i1 = min_element(ans.begin(), ans.end()) - ans.begin();
	int i2 = max_element(ans.begin(), ans.end()) - ans.begin();

	ll MAX = 0;
	int ans1 = -1, ans2 = -1;
	for (int i = 0; i < ans.size(); i++) {
		pii p1 = ans[i1], p1_nxt = ans[(i1 + 1) % ans.size()];
		pii p2 = ans[i2], p2_nxt = ans[(i2 + 1) % ans.size()];

		ll curr = sqrdist(p1, p2);
		if (curr > MAX) {
			MAX = curr;
			ans1 = i1, ans2 = i2;
		}

		pii v1 = sub(p1, p1_nxt);
		pii v2 = sub(p2_nxt, p2);

		if (ccw2(v1, v2) > 0) i1 = (i1 + 1) % ans.size();
		else i2 = (i2 + 1) % ans.size();
	}

	cout << ans[ans1].first << " " << ans[ans1].second << " " << ans[ans2].first << " " << ans[ans2].second << '\n';
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

ll ccw(pii a, pii b, pii c) {
	pii u = sub(b, a);
	pii v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	if (ret) ret /= abs(ret);
	return ret;
}

ll ccw2(pii a, pii b) {
	ll ret = a.first * b.second - a.second * b.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { b.first - a.first, b.second - a.second };
}

ll sqrdist(pii a, pii b) {
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return dx * dx + dy * dy;
}