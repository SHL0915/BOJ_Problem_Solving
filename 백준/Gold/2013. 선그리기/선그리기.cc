#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
int parent[10005];
pair<pii, pii> arr[10005];
int mark[10005];

void Union(int a, int b);
int Find(int a);
ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);
int check(pii a, pii b, pii c, pii d);


void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 1; i <= N; i++) {
		double a, b, c, d;
		cin >> a >> b >> c >> d;
		arr[i].first.first = (ll)(a * 100 + 0.5);
		arr[i].first.second = (ll)(b * 100 + 0.5);
		arr[i].second.first = (ll)(c * 100 + 0.5);
		arr[i].second.second = (ll)(d * 100 + 0.5);
		if (arr[i].first > arr[i].second) swap(arr[i].first, arr[i].second);
		for (int j = 1; j < i; j++) {
			if (Find(j) != i) Union(j, i);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) mark[Find(i)] = 1;
	for (int i = 1; i <= N; i++) cnt += mark[i];

	cout << cnt;
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

void Union(int a, int b) {
	if (check(arr[a].first, arr[a].second, arr[b].first, arr[b].second)) {
		arr[b] = { min(arr[a].first, arr[b].first), max(arr[a].second, arr[b].second) };
		parent[a] = b;
	}
	return;
}

int Find(int a) {
	if (parent[a] == a) return parent[a];
	else return parent[a] = Find(parent[a]);
}

ll ccw(pii a, pii b, pii c) {
	ll res = (a.first * b.second - a.second * b.first) + (b.first * c.second - b.second * c.first) + (c.first * a.second - c.second * a.first);
	if (res) res /= abs(res);
	return res;
}

int check(pii a, pii b, pii c, pii d) {
	ll ccw1 = ccw(a, b, c);
	ll ccw2 = ccw(a, b, d);

	if (ccw1 == 0 && ccw2 == 0) {
		if (a <= d && b >= c) return 1;
		else return 0;
	}
	else return 0;
}