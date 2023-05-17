#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int W, P, cnt;
vector <int> graph[1005];
pii arr[1005];
pair <int, pii> pipe[1005];
int A[1005], B[1005], mark[1005];

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);
int cross(pii a, pii b, pii c, pii d);
void DFS(int node, int color);

void solve() {
	cin >> W >> P;
	for (int i = 1; i <= W; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 1; i <= P; i++) cin >> pipe[i].first >> pipe[i].second.first >> pipe[i].second.second;
	
	for (int i = 1; i <= P; i++) {
		for (int j = 1; j <= P; j++) {
			if (pipe[i].first == pipe[j].first) continue;
			int res = cross(arr[pipe[i].first], pipe[i].second, arr[pipe[j].first], pipe[j].second);

			if (res) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	memset(mark, -1, sizeof(mark));

	for (int i = 1; i <= P; i++) if (mark[i] == -1) DFS(i, 0);

	cout << "possible";
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

void DFS(int node, int color) {
	if (mark[node] != -1) {
		if (mark[node] != color) {
			cout << "impossible";
			exit(0);
		}
		else return;
	}
	mark[node] = color;

	for (int i : graph[node]) DFS(i, color ^ 1);
	return;
}