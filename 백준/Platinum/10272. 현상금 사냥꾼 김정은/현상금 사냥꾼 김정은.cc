#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const double INF = 0x3f3f3f3f;

int N;
pii arr[513];
double table[513][513];

double DP(int a, int b);
double dist(int a, int b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) table[i][j] = INF;
	}
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	cout << DP(0, 0) << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(6);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

double DP(int a, int b) {
	if (a == N - 1) return dist(b, N - 1);
	if (b == N - 1) return dist(a, N - 1);
	double& ret = table[a][b];
	if (ret != INF) return ret;
	ret = INF;
	int next = max(a, b) + 1;
	ret = min(ret, DP(a, next) + dist(b, next));
	ret = min(ret, DP(next, b) + dist(a, next));
	return ret;
}

double dist(int a, int b) {
	ll x1 = arr[a].first;
	ll x2 = arr[b].first;
	ll y1 = arr[a].second;
	ll y2 = arr[b].second;
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}