#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, R;
pii arr[200005];

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);
double dotNline(pii a, pii b, pii c);
double dist(pii a, pii b);

void solve() {
	cin >> N >> R;
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

	double ans = 1000000000000;

	int idx = 0;
	for (int i = 0; i < ch.size(); i++) {
		int org = idx;
		while (1) {
			int next = (idx + 1) % (ch.size());
			if (dotNline(ch[i], ch[(i + 1) % ch.size()], ch[next]) < dotNline(ch[i], ch[(i + 1) % ch.size()], ch[idx])) break;
			idx = next;
			if (idx == org) break;
		}
		ans = min(ans, dotNline(ch[i], ch[(i + 1) % ch.size()], ch[idx]));
	}

	cout << ans;
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

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
}

double dotNline(pii a, pii b, pii c) {
	pii u = sub(b, a);
	pii v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	ret = abs(ret);
	return (double)ret / dist(a, b);
}

double dist(pii a, pii b) {
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}