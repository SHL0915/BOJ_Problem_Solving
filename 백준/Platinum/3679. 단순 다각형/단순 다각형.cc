#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pair <pii, int> arr[2005];

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first.first >> arr[i].first.second;
		arr[i].second = i;
	}
	sort(arr, arr + N);
	sort(arr + 1, arr + N, [&](pair <pii, int> a, pair <pii, int> b) {
		ll res = ccw(arr[0].first, a.first, b.first);
		if (res) return res > 0;
		else return a < b;
		});

	int ptr = N - 1;
	while (ptr) {
		if (ccw(arr[0].first, arr[ptr].first, arr[ptr - 1].first) == 0) ptr--;
		else break;
	}

	for (int i = 0; i < ptr; i++) cout << arr[i].second << " ";
	for (int i = N - 1; i >= ptr; i--) cout << arr[i].second << " ";
	cout << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

ll ccw(pii a, pii b, pii c) {
	pii u = sub(b, a), v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
}