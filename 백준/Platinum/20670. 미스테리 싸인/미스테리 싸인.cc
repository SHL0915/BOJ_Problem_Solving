#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M, K;
vector <pii> a, b;

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);
int isIn(vector <pii>& arr, pii dot);

void solve() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		a.push_back({ x,y });
	}

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		b.push_back({ x,y });
	}

	int ans = 0;
	for (int i = 0; i < K; i++) {
		pii query;
		cin >> query.first >> query.second;
		if (isIn(a, query) == 1 && isIn(b, query) == 0) continue;
		ans++;
	}

	if (ans == 0) cout << "YES";
	else cout << ans;

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

int isIn(vector <pii>& arr, pii dot) {
	if (ccw(arr[0], arr[1], dot) < 0 || ccw(arr[0], arr[arr.size() - 1], dot) > 0) return 0;
	int l = 1, r = arr.size() - 1;

	while (l < r) {
		int mid = (l + r) / 2;
		ll res = ccw(arr[0], arr[mid], dot);
		if (res >= 0) l = mid + 1;
		else r = mid;
	}

	return ccw(arr[l - 1], arr[l], dot) >= 0;
}