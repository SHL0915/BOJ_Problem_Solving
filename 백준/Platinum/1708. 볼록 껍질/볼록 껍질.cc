#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[100001];

bool cmp(pii a, pii b);
ll CCW(pii a, pii b, pii c);
pii sub(pii a, pii b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

	sort(arr, arr + N);
	sort(arr + 1, arr + N, cmp);

	vector <pii> ans;
	ans.push_back(arr[0]);
	ans.push_back(arr[1]);

	for (int i = 2; i < N; i++) {
		pii c = arr[i];
		while (ans.size() - 1) {
			pii b = ans.back();
			ans.pop_back();

			pii a = ans.back();

			if (CCW(b, c, a) > 0) {
				ans.push_back(b);
				break;
			}
		}
		ans.push_back(c);
	}
	cout << ans.size();
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
	ll ccw = CCW(arr[0], a, b);
	if (ccw) return ccw > 0;
	else return a < b;
}

ll CCW(pii a, pii b, pii c) {
	pii u = sub(b, a);
	pii v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
}