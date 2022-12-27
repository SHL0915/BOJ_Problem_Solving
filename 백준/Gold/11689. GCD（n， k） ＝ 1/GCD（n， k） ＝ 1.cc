#include <bits/stdc++.h>
using namespace std;

long long N, temp;
int table[10000000];
vector <int> primeNum;
vector <long long> p;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (long long i = 2; i < 10000000; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			for (long long j = i * i; j < 10000000; j += i) table[j] = 1;
		}
	}
	cin >> N;
	temp = N;
	for (int i = 0; i < primeNum.size(); i++) {
		int now = primeNum[i];
		if (now * now > temp) break;
		if (temp % now == 0) {
			p.push_back(now);
			while (1) {
				if (temp % now == 0) temp /= now;
				else break;
			}
		}
	}
	if (temp != 1) p.push_back(temp);
	long long ans = N;
	for (int i = 0; i < p.size(); i++) {
		ans /= p[i];
		ans *= (p[i] - 1);
	}
	cout << ans;
	return 0;
}