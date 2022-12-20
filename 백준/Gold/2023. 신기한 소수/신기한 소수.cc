#include <bits/stdc++.h>
using namespace std;

int N;
int table[100001];
vector <int> primeNum;

void BackTracking(int n, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (long long i = 2; i <= 100000; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			for (long long j = i * i; j <= 100000; j += i) table[j] = 1;
		}
	}
	for (int i = 0; i < 10; i++) BackTracking(i, 1);
	return 0;
}

void BackTracking(int n, int k) {
	if (k == N) {        
		if (n == 0 || n == 1) return;
		for (int i = 0; i < primeNum.size(); i++) {
			if (primeNum[i] * primeNum[i] > n) break;
			if (n % primeNum[i] == 0) return;
		}
		cout << n << '\n';
	}
	else {
		if (n == 0 || n == 1) return;
		for (int i = 0; i < primeNum.size(); i++) {
			if (primeNum[i] * primeNum[i] > n) break;
			if (n % primeNum[i] == 0) return;
		}
		for (int i = 0; i < 10; i++) BackTracking(n * 10 + i, k + 1);		
	}
}