#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[10];
pii place[10];
int bt[10];
int mark[10];

ll CCW(pii a, pii b, pii c);
pii sub(pii a, pii b);
bool check(pair<pii, pii> a, pair<pii, pii> b);
void BackTracking(int k);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 0; i < N; i++) cin >> place[i].first >> place[i].second;
	BackTracking(0);
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

ll CCW(pii a, pii b, pii c) {
	pii u = sub(b, a), v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
}

bool check(pair<pii, pii> a, pair<pii, pii> b) {
	ll ccw1 = CCW(a.first, a.second, b.first) * CCW(a.first, a.second, b.second);
	ll ccw2 = CCW(b.first, b.second, a.first) * CCW(b.first, b.second, a.second);
	if (ccw1 == 0 && ccw2 == 0) {
		if (a.first > a.second) swap(a.first, a.second);
		if (b.first > b.second) swap(b.first, b.second);
		if (a.first <= b.second && b.first <= a.second) return true;
		else return false;
	}
	else if (ccw1 <= 0 && ccw2 <= 0) return true;
	else return false;
}

void BackTracking(int k) {
	if (k == N) {
		for (int i = 0; i < N; i++) {
			pair<pii, pii> a = { arr[i], place[bt[i]] };
			for (int j = i + 1; j < N; j++) {
				pair<pii, pii> b = { arr[j], place[bt[j]] };
				if (check(a, b) == true) return;
			}
		}
		for (int i = 0; i < N; i++) cout << bt[i] + 1 << '\n';
		exit(0);
	}
	else {
		for (int i = 0; i < N; i++) {
			if (mark[i] == 0) {
				mark[i] = 1;
				bt[k] = i;
				BackTracking(k + 1);
				mark[i] = 0;
			}
		}
	}
}