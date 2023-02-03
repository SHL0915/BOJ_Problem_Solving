#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[51];

bool cmp1(pii a, pii b);
bool cmp2(pii a, pii b);
ll CCW(pii a, pii b, pii c);
pii sub(pii a, pii b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N, cmp1);
	sort(arr + 1, arr + N, cmp2);
	
	vector <pii> ans;
	ans.push_back(arr[0]);
	ans.push_back(arr[1]);

	for (int i = 2; i < N; i++) {
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

	cout << ans.size() << '\n';
	cout << ans[0].first << " " << ans[0].second << '\n';
	for (int i = ans.size() - 1; i > 0; i--) cout << ans[i].first << " " << ans[i].second << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

bool cmp1(pii a, pii b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

bool cmp2(pii a, pii b) {
	ll ccw = CCW(arr[0], a, b);
	if (ccw) return ccw > 0;
	return cmp1(a, b);
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