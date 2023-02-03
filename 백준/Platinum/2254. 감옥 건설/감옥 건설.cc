#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, cnt;
pii P, f;
set <pii> dots;

bool cmp(pii a, pii b);
ll CCW(pii a, pii b, pii c);
pii sub(pii a, pii b);

void solve() {
	cin >> N;
	cin >> P.first >> P.second;	
	for (int i = 0; i < N; i++) {
		pii a;
		cin >> a.first >> a.second;
		dots.insert(a);
	}
	while (dots.size()) {
		vector <pii> arr;
		for (auto i = dots.begin(); i != dots.end(); i++) arr.push_back(*i);
		sort(arr.begin(), arr.end());
		f = arr[0];
		sort(arr.begin() + 1, arr.end(), cmp);

		vector <pii> ans;
		ans.push_back(arr[0]);
		ans.push_back(arr[1]);
		for (int i = 2; i < arr.size(); i++) {
			pii c = arr[i];
			while (ans.size() >= 2) {
				pii b = ans.back();
				ans.pop_back();
				pii a = ans.back();
				if (CCW(a, b, c) > 0) {
					ans.push_back(b);
					break;
				}
			}
			ans.push_back(c);
		}

		int flag = 0;
		ll ccw = CCW(P, ans[0], ans[1]);
		for (int i = 2; i < ans.size(); i++) {
			if (CCW(P, ans[i - 1], ans[i]) != ccw) {
				flag = 1;
				break;
			}
		}
		if (CCW(P, ans[ans.size() - 1], ans[0]) != ccw) flag = 1;
		if (flag) break;
		cnt++;

		for (int i = 0; i < ans.size(); i++) dots.erase(ans[i]);
	}
	cout << cnt;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

bool cmp(pii a, pii b) {
	ll ccw = CCW(f, a, b);
	if (ccw) return ccw > 0;
	else return a < b;
}

ll CCW(pii a, pii b, pii c) {
	pii u = sub(b, a), v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
}