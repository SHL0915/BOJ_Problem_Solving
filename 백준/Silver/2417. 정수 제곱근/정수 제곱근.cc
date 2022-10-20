#include <iostream>
#include <cmath>
using namespace std;

unsigned long long n;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	else if (n == 1) {
		cout << 1;
		return 0;
	}
	unsigned long long ans = sqrt(n);
	for (unsigned long long i = ans - 2; ; i++) {
		if (i * i >= n) {
			cout << i;
			break;
		}
	}
	return 0;
}