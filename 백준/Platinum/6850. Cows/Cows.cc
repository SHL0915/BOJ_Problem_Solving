#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[10005];

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);

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
	ch.push_back(arr[0]);
	ch.push_back(arr[1]);

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

	ll ans = 0;
	for (int i = 0; i < ch.size(); i++) {
		int nxt = (i + 1) % ch.size();
		ans += (ch[i].first * ch[nxt].second - ch[i].second * ch[nxt].first);
	}

	ans /= 100;

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