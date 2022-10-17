#include <iostream>
#include <cmath>
using namespace std;

int t;
unsigned long long n;

int main(void) {
	cin >> t;
	while (t--) {
		int flag = 0;
		cin >> n;
		if (n == 0 || n == 1 || n == 2) {
			cout << 2 << '\n';
			continue;
		}
		for (unsigned long long i = n; ; i++) {
			if (flag == 1) break;
			for (unsigned long long j = 2; j <= (unsigned long long)sqrt(i) + 1; j++) {
				if (i % j == 0) break;
				if (j == (unsigned long long)sqrt(i) + 1) {
					cout << i << '\n';
					flag = 1;
					break;
				}
			}
		}
	}
	return 0;
}