#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<double, double>;

int N;
double X, V;
pii arr[101];

void solve() {
	cin >> N >> X >> V;
	for (int i = 0; i < N; i++) {
		int l, r;
		double v;
		cin >> l >> r >> v;
		arr[i] = { r - l, v };
	}
	double sum = 0;
	for (int i = 0; i < N; i++) sum += (arr[i].first * arr[i].second);
	
	sum /= X;
	sum *= sum;

	double dx2 = V * V - sum;

	if (dx2 <= 0) {
		cout << "Too hard";
		return;
	}

	dx2 = sqrt(dx2);

	if (dx2 < V / 2) {
		cout << "Too hard";
		return;
	}

	cout << X / dx2 << '\n';
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(3);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}