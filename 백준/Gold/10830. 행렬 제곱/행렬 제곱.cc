#include <iostream>
using namespace std;

int N;
long long B;
long long A[5][5];
long long mul[5][5];

void multiply(long long A[5][5], long long B[5][5]);

int main(void) {
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			mul[i][j] = A[i][j];
		}
	}	
	long long bit = 1;
	while (1) {
		if (bit > (B - 1)) break;
		if (bit & (B - 1)) multiply(A, mul);
		bit <<= 1;
		multiply(mul, mul);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << A[i][j] % 1000 << " ";
		cout << "\n";
	}
	return 0;
}

void multiply(long long A[5][5], long long B[5][5]) {
	long long temp[5][5] = { 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				temp[i][j] += (A[i][k] * B[k][j]) % 1000;
				temp[i][j] %= 1000;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) A[i][j] = temp[i][j];
	}
	return;
}