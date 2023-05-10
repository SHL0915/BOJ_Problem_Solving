#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M;
pii A[105], B[105];

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);
int isIn(vector <pii>& arr, pii dot);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i].first >> A[i].second;
	for (int i = 0; i < M; i++) cin >> B[i].first >> B[i].second;

	vector <pii> hull_a, hull_b;

	if (N == 1) hull_a.push_back(A[0]);
	else {
		sort(A, A + N);
		sort(A + 1, A + N, [&](pii a, pii b) {
			ll res = ccw(A[0], a, b);
			if (res) return res > 0;
			else return a < b;
			});

		hull_a.push_back(A[0]); hull_a.push_back(A[1]);
		for (int i = 2; i < N; i++) {
			pii c = A[i];
			while (hull_a.size() >= 2) {
				pii b = hull_a.back(); hull_a.pop_back();
				pii a = hull_a.back();
				if (ccw(a, b, c) > 0) {
					hull_a.push_back(b);
					break;
				}
			}
			hull_a.push_back(c);
		}
	}

	if (M == 1) hull_b.push_back(B[0]);
	else {
		sort(B, B + M);
		sort(B + 1, B + M, [&](pii a, pii b) {
			ll res = ccw(B[0], a, b);
			if (res) return res > 0;
			else return a < b;
			});

		hull_b.push_back(B[0]); hull_b.push_back(B[1]);
		for (int i = 2; i < M; i++) {
			pii c = B[i];
			while (hull_b.size() >= 2) {
				pii b = hull_b.back(); hull_b.pop_back();
				pii a = hull_b.back();
				if (ccw(a, b, c) > 0) {
					hull_b.push_back(b);
					break;
				}
			}
			hull_b.push_back(c);
		}
	}

	N = hull_a.size(); M = hull_b.size();

	if (N >= 3 && M >= 3) {		
		int flag = 0;
		for (int i = 0; i < hull_b.size(); i++) {
			pii now = hull_b[i];
			if (isIn(hull_a, now)) flag = 1;
		}
		for (int i = 0; i < hull_a.size(); i++) {
			pii now = hull_a[i];
			if (isIn(hull_b, now)) flag = 1;
		}

		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}
	else if (N == 1) {
		if (M == 1) cout << "YES\n";
		else if (M == 2) {
			sort(hull_b.begin(), hull_b.end());
			ll res = ccw(hull_b[0], hull_b[1], hull_a[0]);
			if (res == 0 && hull_a[0].first >= hull_b[0].first && hull_a[0].first <= hull_b[1].first) cout << "NO\n";
			else cout << "YES\n";
		}
		else {			
			pii now = hull_a[0];
			if (isIn(hull_b, now)) cout << "NO\n";
			else cout << "YES\n";
		}
	}
	else if (N == 2) {
		if (M == 1) {
			sort(hull_a.begin(), hull_a.end());
			ll res = ccw(hull_a[0], hull_a[1], hull_b[0]);
			if (res == 0 && hull_b[0].first >= hull_a[0].first && hull_b[0].first <= hull_a[1].first) cout << "NO\n";
			else cout << "YES\n";
		}
		else if (M == 2) {
			ll ccw1 = ccw(hull_a[0], hull_a[1], hull_b[0]) * ccw(hull_a[0], hull_a[1], hull_b[1]);
			ll ccw2 = ccw(hull_b[0], hull_b[1], hull_a[0]) * ccw(hull_b[0], hull_b[1], hull_a[1]);
			if (ccw1 == 0 && ccw2 == 0) {
				if (hull_a[0] > hull_a[1]) swap(hull_a[0], hull_a[1]);
				if (hull_b[0] > hull_b[1]) swap(hull_b[0], hull_b[1]);
				if (hull_a[0] <= hull_b[1] && hull_b[0] <= hull_a[1]) cout << "NO\n";
				else cout << "YES\n";
			}
			else if (ccw1 <= 0 && ccw2 <= 0) cout << "NO\n";
			else cout << "YES\n";
		}
		else {			
			int flag = 0;
			for (int i = 0; i < N; i++) {
				pii now = hull_a[i];
				if (isIn(hull_b, now)) flag = 1;
			}

			if (flag) cout << "NO\n";
			else cout << "YES\n";
		}
	}
	else {
		int flag = 0;
		for (int i = 0; i < hull_b.size(); i++) {
			pii now = hull_b[i];
			if (isIn(hull_a, now)) flag = 1;
		}

		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}
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