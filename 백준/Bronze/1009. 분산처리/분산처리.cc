#include <iostream>
using namespace std;

int T, a, b;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		int ans = 1;
		for (int j = 1; j <= b; j++) {
			ans *= a;
			ans %= 10;
		}
		ans %= 10;
		if (ans == 0) ans = 10;
		cout << ans << "\n";
	}
	return 0;
}