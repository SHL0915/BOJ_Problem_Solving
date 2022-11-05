#include <iostream>
using namespace std;

int R, G;

int GCD(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> G;
	int gcd = GCD(R, G);
	for (long long i = 1; ; i++) {
		if (i * i > gcd) break;
		if (gcd % i == 0) {
			cout << i << " " << R / i << " " << G / i << '\n';
			if (i * i == gcd) break;
			cout << gcd / i << " " << R / (gcd / i) << " " << G / (gcd / i) << '\n';
		}
	}			
	return 0;
}

int GCD(int A, int B) {
	if (A == B) return A;
	else if (A > B) {
		if (A % B == 0) return B;
		else return GCD(A % B, B);
	}
	else {
		if (B % A == 0) return A;
		else return GCD(B % A, A);
	}
}