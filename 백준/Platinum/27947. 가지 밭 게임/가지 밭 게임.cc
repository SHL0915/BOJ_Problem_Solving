#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, A;
pii org[100005];

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);
int check(ll k);

void solve() {
	cin >> N >> A;
	for (int i = 0; i < 3; i++) cin >> org[i].first >> org[i].second;
	for (int i = 0; i < N; i++) cin >> org[3 + i].first >> org[3 + i].second;

	ll l = 1, r = N;
	ll ans = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}

	if (ans == 0) cout << "draw";
	else if (ans % 2) cout << "wapas";
	else cout << "wider";

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

int check(ll k) {
	vector <pii> arr;
	for (int i = 0; i < k + 3; i++) arr.push_back(org[i]);


	sort(arr.begin(), arr.end());
	sort(arr.begin() + 1, arr.end(), [&](pii a, pii b) {
		ll res = ccw(arr[0], a, b);
		if (res) return res > 0;
		else return a < b;
		});

	vector <pii> ch;
	ch.push_back(arr[0]); ch.push_back(arr[1]);

	for (int i = 2; i < arr.size(); i++) {
		pii c = arr[i];
		while (ch.size() >= 2) {
			pii b = ch.back(); ch.pop_back();
			pii a = ch.back();
			if (ccw(a, b, c) >= 0) {
				ch.push_back(b);
				break;
			}
		}
		ch.push_back(c);
	}

	ll area = 0;
	for (int i = 0; i < ch.size(); i++) area += ch[i].first * ch[(i + 1) % ch.size()].second - ch[i].second * ch[(i + 1) % ch.size()].first;
	area = abs(area);

	if (area >= A * 2) return 1;
	else return 0;
}