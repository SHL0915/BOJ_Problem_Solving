#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const double INF = 0x3f3f3f3f;

struct trick {
	int t, d;
	double p;
};

int N, R, M;
trick arr[55];
double table[55][5005];

int check(double expect);
double DP(int i, int penalty, double expect);

void solve() {
	cin >> N >> R >> M;
	for (int i = 0; i < M; i++) cin >> arr[i].t >> arr[i].p >> arr[i].d;

	double l = 0, r = 249999999;
	while (r - l > 1e-7) {
		double mid = (r + l) / 2;
		int res = check(mid);

		if (res) r = mid;
		else l = mid;
	}

	cout << (r + l) / 2;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(9);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int check(double expect) {
	memset(table, 0, sizeof(table));
	double val = arr[0].t + DP(0, 0, expect);

	if (val < expect) return 1;
	else return 0;
}

double DP(int i, int penalty, double expect) {
	if (penalty >= R - N) return INF;
	if (i == M) return 0;
	double& ret = table[i][penalty];
	if (ret != 0) return ret;

	if (i == M - 1) {
		ret += arr[i].p * (N - arr[i].t + DP(i + 1, penalty, expect));
		ret += (1 - arr[i].p) * min(expect, N - arr[i].t + arr[i].d + DP(i + 1, penalty + arr[i].d, expect));
	}
	else {
		ret += arr[i].p * (arr[i + 1].t - arr[i].t + DP(i + 1, penalty, expect));
		ret += (1 - arr[i].p) * min(expect, arr[i + 1].t - arr[i].t + arr[i].d + DP(i + 1, penalty + arr[i].d, expect));
	}

	return ret;
}