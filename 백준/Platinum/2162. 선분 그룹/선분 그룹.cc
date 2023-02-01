#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, cnt, ans;
pair<pii, pii> arr[3001];
int parent[3001];
int sz[3001];
int mark[3001];

int Find(int a);
void Union(int a, int b);
ll CCW(pii a, pii b, pii c);
pii sub(pii a, pii b);
bool check(pair<pii, pii> a, pair<pii, pii> b);


void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;
		parent[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (Find(i) == Find(j)) continue;
			else if (check(arr[i], arr[j])) Union(i, j);
		}
	}
	for (int i = 0; i < N; i++) {
		int now = Find(i);
		if (mark[now] == 0) {
			mark[now] = 1;
			cnt++;
			ans = max(ans, sz[now]);
		}
	}
	cout << cnt << '\n' << ans;
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

int Find(int a) {
	if (parent[a] == a) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) {
		parent[a] = b;
		sz[b] += sz[a];
	}
	else {
		parent[b] = a;
		sz[a] += sz[b];
	}
	return;
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

bool check(pair<pii, pii> a, pair<pii, pii> b) {
	ll ccw1 = CCW(a.first, a.second, b.first) * CCW(a.first, a.second, b.second);
	ll ccw2 = CCW(b.first, b.second, a.first) * CCW(b.first, b.second, a.second);
	if (ccw1 == 0 && ccw2 == 0) {
		if (a.first > a.second) swap(a.first, a.second);
		if (b.first > b.second) swap(b.first, b.second);
		return (a.first <= b.second && b.first <= a.second);
	}
	else if (ccw1 <= 0 && ccw2 <= 0) return true;
	else return false;
}