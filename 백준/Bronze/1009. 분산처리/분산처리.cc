#include <iostream>
using namespace std;

int T;
int A, B;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> A >> B;
		long long result = 1;
		long long temp = A;
		long long bit = 1;
		while (bit <= B) {
			if (bit & B) result *= temp;
			temp = (temp * temp) % 10;
			bit <<= 1;
		}
		if (result % 10 == 0) cout << 10 << '\n';
		else cout << result % 10 << '\n';
	}
	return 0;
}