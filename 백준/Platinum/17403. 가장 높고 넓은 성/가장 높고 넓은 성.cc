#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[1005];
int ans[1005];

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

	int floor = 1;
	while (1) {
		vector <pair<pii, int>> dots;
		for (int i = 0; i < N; i++) {
			if (ans[i] == 0) dots.push_back({ arr[i],i });
		}

		if (dots.size() <= 2) break;
		sort(dots.begin(), dots.end());
		sort(dots.begin() + 1, dots.end(), [&](pair<pii, int> a, pair<pii, int> b) {
			ll res = ccw(dots[0].first, a.first, b.first);
			if (res) return res > 0;
			else return a.first < b.first;
			});

		vector <pair<pii, int>> ch;
		ch.push_back(dots[0]);
		ch.push_back(dots[1]);

		for (int i = 2; i < dots.size(); i++) {
			pair<pii, int> c = dots[i];
			while (ch.size() >= 2) {
				pair<pii, int> b = ch.back(); ch.pop_back();
				pair<pii, int> a = ch.back();
				if (ccw(a.first, b.first, c.first) > 0) {
					ch.push_back(b);
					break;
				}
			}
			ch.push_back(c);
		}

		if (ch.size() <= 2) break;

		for (int i = 0; i < ch.size(); i++) {
			ans[ch[i].second] = floor;
		}

		floor++;
	}

	for (int i = 0; i < N; i++) cout << ans[i] << " ";
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