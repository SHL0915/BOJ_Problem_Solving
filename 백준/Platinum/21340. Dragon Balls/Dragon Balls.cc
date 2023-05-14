#include <bits/stdc++.h>
#include <random>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll in;

void solve() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99999);

	cin >> N;
	for (int i = 0; i < N; i++) {
		while (1) {
			ll x = dis(gen), y = dis(gen);
			cout << x << " " << y << endl;
			cin >> in; if (in == 0) break;
			ll d1 = in;

			cout << x << " " << y - 1 << endl;
			cin >> in; if (in == 0) break;
			ll d2 = in;

			double a = 0;
			double b = (double)(d2 - d1 + y * y - (y - 1) * (y - 1)) / 2;

			double x1 = x + sqrt(d1 - (b - y) * (b - y));
			double y1 = b;

			ll qx = round(x1), qy = round(y1);

			cout << qx << " " << qy << endl;
			cin >> in; if (in == 0) break;

			x1 = x - sqrt(d1 - (b - y) * (b - y));
			qx = round(x1);

			cout << qx << " " << qy << endl;
			cin >> in; if (in == 0) break;
		}
	}

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}