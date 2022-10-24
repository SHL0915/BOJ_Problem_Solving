#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int T;

long long disSqr(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		long long x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << '\n';
			continue;
		}
		long long dis = disSqr(x1, y1, x2, y2);
		if (dis >= max(r1 * r1, r2 * r2)) {
			if (dis > r1 * r1 + 2 * r1 * r2 + r2 * r2) cout << 0 << '\n';
			else if (dis == r1 * r1 + 2 * r1 * r2 + r2 * r2) cout << 1 << '\n';
			else cout << 2 << '\n';
		}
		else {
			if (dis < r1 * r1 - 2 * r1 * r2 + r2 * r2) cout << 0 << '\n';
			else if (dis == r1 * r1 - 2 * r1 * r2 + r2 * r2) cout << 1 << '\n';
			else cout << 2 << '\n';
		}
	}
	return 0;
}