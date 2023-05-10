#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[100005];

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

	vector <pii> ch;
	ch.push_back(arr[0]), ch.push_back(arr[1]);

	for (int i = 2; i < N; i++) {
		pii c = arr[i];
		while (ch.size() >= 2) {
			pii b = ch.back(); ch.pop_back();
			pii a = ch.back();
			if (ccw(a, b, c) > 0) {
				ch.push_back(b);
				break;
			}
		}
		ch.push_back(c);
	}

	int a = min_element(ch.begin(), ch.end()) - ch.begin();
	int b = max_element(ch.begin(), ch.end()) - ch.begin();

	ll MAX = 0;
	for (int i = 0; i < ch.size(); i++) {
		pii p1 = ch[a], p1_nxt = ch[(a + 1) % ch.size()];
		pii p2 = ch[b], p2_nxt = ch[(b + 1) % ch.size()];

		MAX = max(MAX, sqrdist(p1, p2));

		pii u = sub(p1, p1_nxt);
		pii v = sub(p2_nxt, p2);

		if (ccw2(u, v) > 0) a = (a + 1) % ch.size();
		else b = (b + 1) % ch.size();
	}

	cout << sqrt(MAX);
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(9);
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

ll ccw2(pii a, pii b) {
	ll ret = a.first * b.second - a.second * b.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
}

ll sqrdist(pii a, pii b) {
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return dx * dx + dy * dy;
}