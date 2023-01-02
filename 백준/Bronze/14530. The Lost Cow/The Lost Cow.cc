#include <bits/stdc++.h>
using namespace std;

int x, y, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> x >> y;
	int now = x;
	int dist = 1;
	for (int i = 0; ; i++) {
		if (i % 2) {
			if (y < x && y >= x - dist) {
				ans += (now - y);
				break;
			}
			ans += (now - (x - dist));
			now = x - dist;
		}
		else {
			if (x < y && y <= x + dist) {
				ans += (y - now);
				break;
			}
			ans += ((x + dist) - now);
			now = x + dist;
		}
		dist *= 2;
	}
	cout << ans;
	return 0;
}