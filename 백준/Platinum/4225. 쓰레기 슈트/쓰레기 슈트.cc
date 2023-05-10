#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[105];

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);
double dotNline(pii a, pii b, pii c);
double dist(pii a, pii b);

void solve() {
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

	double ret = 1000000000;

	for (int i = 0; i < ans.size(); i++) {
		double cal = 0;
		for (int j = 0; j < N; j++) cal = max(cal, dotNline(ans[i], ans[(i + 1) % ans.size()], arr[j]));
		ret = min(ret, cal);
	}

	ret += 0.005;
	cout << ret << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(2);
	int t = 1;
	//cin >> t;
	while (1) {
		cin >> N;
		if (N == 0) break;
		cout << "Case " << t << ": ";
		t++;
		solve();
	}
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