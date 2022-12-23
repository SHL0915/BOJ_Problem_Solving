#include <bits/stdc++.h>
using namespace std;

int table[1000001];
vector <long long> primeNum;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (long long i = 2; i <= 100000; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			for (long long j = i * i; j <= 100000; j += i) table[j] = 1;
		}
	}
	while (1) {
		long long a, p;
		cin >> p >> a;
		if (a == 0 && p == 0) break;
		int flag = 0;
		for (int i = 0; i < primeNum.size(); i++) {
			long long now = primeNum[i];
			if (now * now > p) break;
			if (p % now == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "no\n";
			continue;
		}
		long long result = 1;
		long long temp = a;
		long long bit = 1;
		while (bit <= p) {
			if (p & bit) result = (result * temp) % p;
			temp = (temp * temp) % p;
			bit <<= 1;
		}
		if (result == a % p) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}