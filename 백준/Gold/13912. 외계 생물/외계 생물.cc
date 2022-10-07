#include <iostream>
using namespace std;

long long mod = 1000000007;

int H;
long long table[11];
long long factorial[2049];
long long ifactorial[2049];

void pre(void);
long long comb(int N, int K);
long long exp(int N);

int main(void) {
	cin >> H;
	pre();
	table[0] = 1;
	for (int i = 1; i <= 10; i++) table[i] = ((comb(exp(i + 1) - 2, exp(i) - 1) * table[i - 1]) % mod * table[i - 1]) % mod;
	cout << table[H];
	return 0;	
}

void pre(void) {
	factorial[0] = 1;
	for (int i = 1; i <= 2048; i++) factorial[i] = (factorial[i - 1] * i) % mod;
	long long exponential = factorial[2048];
	long long result = 1;
	int bit = 1;
	for (int i = 0; i <= 31; i++) {
		if (bit & (mod - 2))
			result = (result * exponential) % mod;
		exponential = (exponential * exponential) % mod;
		bit <<= 1;
	}
	ifactorial[2048] = result;
	for (int i = 2047; i >= 0; i--) ifactorial[i] = (ifactorial[i + 1] * (i + 1)) % mod;
	return;
}

long long comb(int N, int K) {
	return ((factorial[N] * ifactorial[K]) % mod * ifactorial[N - K]) % mod;
}

long long exp(int N) {
	long long result = 1;
	for (int i = 0; i < N; i++)
		result *= 2;
	return result;
}