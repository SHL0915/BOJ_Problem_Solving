#include <iostream>
using namespace std;

long long n, k;
long long table[11];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	table[1] = 1;
	table[2] = 2;
	table[3] = 4;
	for (int i = 4; i <= 10; i++) {
		for (int j = 1; j <= 3; j++) {
			table[i] += table[i - j];
		}
	}
	if (k > table[n]) cout << -1;
	else {
		while (k) {
			if (n == 1) {
				cout << 1;
				break;
			}
			else if (n == 2 && k == 2) {
				cout << 2;
				break;
			}
			else if (n == 3 && k == 4) {
				cout << 3;
				break;
			}			
			for (int i = 1; i <= 3; i++) {
				if (n - i == 0) break;
				if (k <= table[n - i]) {
					n -= i;
					if (k == 0) cout << i;
					else cout << i << "+";
					break;
				}
				else k -= table[n - i];
			}
		}
	}
	return 0;
}