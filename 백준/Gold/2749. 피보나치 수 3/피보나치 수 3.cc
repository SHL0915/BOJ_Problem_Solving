#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000;

long long N;
long long mul[2][2] = { {0,1},{1,1} };
long long result[2][2] = { {0,1},{0,0} };

void func1();
void func2();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	N--;
	long long bit = 1;
	while (bit <= N) {
		if (bit & N) func2();		
		bit <<= 1;
		func1();
	}
	cout << result[0][1];
	return 0;
}

void func1() {
	long long temp[2][2] = { {0,0},{0,0} };
	temp[0][0] = (mul[0][0] * mul[0][0] % mod + mul[0][1] * mul[1][0] % mod) % mod;
	temp[1][0] = (mul[1][0] * mul[0][0] % mod + mul[1][1] * mul[1][0] % mod) % mod;
	temp[0][1] = (mul[0][0] * mul[0][1] % mod + mul[0][1] * mul[1][1] % mod) % mod;
	temp[1][1] = (mul[1][0] * mul[0][1] % mod + mul[1][1] * mul[1][1] % mod) % mod;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) mul[i][j] = temp[i][j];
	}
	return;
}

void func2() {
	long long temp[2][2] = { {0,0},{0,0} };
	temp[0][0] = (result[0][0] * mul[0][0] % mod + result[0][1] * mul[1][0] % mod) % mod;
	temp[1][0] = (result[1][0] * mul[0][0] % mod + result[1][1] * mul[1][0] % mod) % mod;
	temp[0][1] = (result[0][0] * mul[0][1] % mod + result[0][1] * mul[1][1] % mod) % mod;
	temp[1][1] = (result[1][0] * mul[0][1] % mod + result[1][1] * mul[1][1] % mod) % mod;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) result[i][j] = temp[i][j];
	}
	return;
}