#include <iostream>
using namespace std;

long long mod = 1000000007;

long long A[2];
long long multiplier[2][2] = { {0,1},{1,1} };

long long n;

void multiply1(long long A[2], long long B[2][2]);
void multiply2(long long A[2][2], long long B[2][2]);

int main(void) {
	cin >> n;
	long long bit = 1;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	else if (n == 1) {
		cout << 1;
		return 0;
	}
	A[0] = 0;
	A[1] = 1;
	while (1) {
		if (bit > (n - 1)) break;
		if (bit & (n - 1)) multiply1(A, multiplier);
		bit <<= 1;
		multiply2(multiplier, multiplier);
	}
	cout << A[1];
	return 0;
}

void multiply1(long long A[2], long long B[2][2]) {
	long long temp[2];
	temp[0] = ((A[0] * B[0][0]) % mod + (A[1] * B[1][0]) % mod) % mod;
	temp[1] = ((A[0] * B[0][1]) % mod + (A[1] * B[1][1]) % mod) % mod;
	A[0] = temp[0];
	A[1] = temp[1];
	return;
}

void multiply2(long long A[2][2], long long B[2][2]) {
	long long temp[2][2];
	temp[0][0] = ((A[0][0] * B[0][0]) % mod + (A[0][1] * B[1][0]) % mod) % mod;
	temp[1][0] = ((A[1][0] * B[0][0]) % mod + (A[1][1] * B[1][0]) % mod) % mod;
	temp[0][1] = ((A[0][0] * B[0][1]) % mod + (A[0][1] * B[1][1]) % mod) % mod;
	temp[1][1] = ((A[1][0] * B[0][1]) % mod + (A[1][1] * B[1][1]) % mod) % mod;
	A[0][0] = temp[0][0];
	A[1][0] = temp[1][0];
	A[0][1] = temp[0][1];
	A[1][1] = temp[1][1];
	return;
}