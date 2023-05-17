#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, ans;
pair <pii, pii> arr[1005];
vector <int> graph[1005];
int edge[1005];
int mark[1005];

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);
int cross(pii a, pii b, pii c, pii d);
void DFS(int node);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;	

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int res = cross(arr[i].first, arr[i].second, arr[j].first, arr[j].second);
			if (res) {
				graph[i].push_back(j);
				graph[j].push_back(i);
				edge[i]++;
				edge[j]++;
				ans--;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (mark[i] == 0 && edge[i]) {
			ans++;
			DFS(i);
		}
	}

	cout << ans;
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

int cross(pii a, pii b, pii c, pii d) {
	ll ccw1 = ccw(a, b, c) * ccw(a, b, d);
	ll ccw2 = ccw(c, d, a) * ccw(c, d, b);
	if (ccw1 == 0 && ccw2 == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (a <= d && b >= c) return 1;
		else return 0;
	}
	else if (ccw1 <= 0 && ccw2 <= 0) return 1;
	else return 0;
}

void DFS(int node) {
	if (mark[node]) return;
	mark[node] = 1;
	if (edge[node]) ans += edge[node] - 1;
	for (int i : graph[node]) DFS(i);
	return;
}