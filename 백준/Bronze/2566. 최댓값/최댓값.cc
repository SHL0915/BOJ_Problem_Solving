#include <iostream>
using namespace std;

int ans, X, Y;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int input;
			cin >> input;
			if (input >= ans) {
				ans = input;
				X = j + 1;
				Y = i + 1;
			}
		}
	}
	cout << ans << '\n' << Y << ' ' << X;
	return 0;
}