#include <iostream>
#include <vector>
using namespace std;

long long N;
long long table[1000001];
long long mark[501];
vector <long long> primeNum;

long long convert(long long n);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (long long i = 2; i <= N; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			table[i] = 1;
			for (long long j = i * i; j <= N; j += i) table[j] = 1;
		}
	}
	for (long long i = 0; i < primeNum.size(); i++) {
		for (long long j = 0; j <= 500; j++) mark[j] = 0;
		long long temp = primeNum[i];
		while (1) {
			if (temp == 1) {
				cout << primeNum[i] << '\n';
				break;
			}
			else if (mark[temp] == 1) break;
			mark[temp] = 1;
			temp = convert(temp);
		}
	}
	return 0;
}

long long convert(long long n) {
	long long result = 0;
	while (n) {
		result += (n % 10) * (n % 10);
		n /= 10;
	}
	return result;
}