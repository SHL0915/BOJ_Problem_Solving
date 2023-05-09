#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
vector <pii> arr;

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;
		char c; cin >> c;
		if (c == 'N') continue;
		arr.push_back({ a,b });
	}

	sort(arr.begin(), arr.end());
	sort(arr.begin() + 1, arr.end(), [&](pii a, pii b) {
		ll res = ccw(arr[0], a, b);
		if (res) return res > 0;
		else return a < b;
		});

	vector <pii> ans, add;

	for (int i = 0; i < arr.size(); i++) {
		pii c = arr[i];
		while (ans.size() >= 2 && ccw(ans[ans.size() - 2], ans.back(), c) < 0) {
			add.push_back(ans.back());
			ans.pop_back();
		}
		ans.push_back(c);
	}

	for (int i = add.size() - 1; i >= 0; i--) ans.push_back(add[i]);

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << '\n';
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

ll ccw(pii a, pii b, pii c) {
	pii u = sub(b, a);
	pii v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
}