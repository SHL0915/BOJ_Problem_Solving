#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
int parent[10005];
pair<pii, pii> arr[10005];

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
		arr[i].first.first = round(a * 100);
		arr[i].first.second = round(b * 100);
		arr[i].second.first = round(c * 100);
		arr[i].second.second = round(d * 100);
		if (arr[i].first > arr[i].second) swap(arr[i].first, arr[i].second);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (Find(i) == Find(j)) continue;
			int a = Find(i), b = Find(j);
			if (check(arr[a].first, arr[a].second, arr[b].first, arr[b].second)) {
				Union(a, b);
				arr[Find(a)] = { min(arr[a].first, arr[b].first), max(arr[a].second, arr[b].second) };
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) if (Find(i) == i) cnt++;

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
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) parent[a] = b;
	else parent[b] = a;	
	return;
}

int Find(int a) {
	if (parent[a] == a) return parent[a];
	else return parent[a] = Find(parent[a]);
}

ll ccw(pii a, pii b, pii c) {
	pii u = sub(b, a);
	pii v = sub(c, b);
	ll res = u.first * v.second - u.second * v.first;
	if (res) res /= abs(res);
	return res;
}

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
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