#include <iostream>
using namespace std;

const long long mod = 1000000007;

long long A, X, ans = 1;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> X;
	long long bit = 1;
	long long temp = A % mod;
	while (bit <= X) {
		if (bit & X) ans = (ans * temp) % mod;
		bit <<= 1;
		temp = (temp * temp) % mod;
	}
	cout << ans;
	return 0;
}