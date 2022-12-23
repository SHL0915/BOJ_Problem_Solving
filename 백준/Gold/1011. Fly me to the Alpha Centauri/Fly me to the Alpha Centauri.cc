#include <bits/stdc++.h>
using namespace std;

int t;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		int delt = y - x;
		long long sum = 0;
		for (int i = 1; ; i++) {
			sum += i;
			if (sum * 2 >= delt) {
				if (delt - sum > sum - i) cout << i * 2 << '\n';
				else cout << i * 2 - 1 << '\n';
				break;
			}
		}
	}
	return 0;
}