#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N;
int table[1000001];
vector <int> primeNum;
set <int> s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (long long i = 2; i <= N; i++) {
		if (table[i] == 0) {
			table[i] = 1;
			primeNum.push_back(i);
			s.insert(i);
			for (long long j = i * i; j <= N; j += i) table[j] = 1;
		}
	}
	for (int i = 0; i < primeNum.size(); i++) {
		for (int j = i; j < primeNum.size(); j++) {
			if (primeNum[i] + primeNum[j] >= N) break;
			for (int k = j; k < primeNum.size(); k++) {
				if (primeNum[i] + primeNum[j] + primeNum[k] >= N) break;
				if (s.count(N - primeNum[i] - primeNum[j] - primeNum[k]) != 0) {
					cout << primeNum[i] << ' ' << primeNum[j] << ' ' << primeNum[k] << ' ' << N - primeNum[i] - primeNum[j] - primeNum[k];
					return 0;
				}
			}
		}
	}
	cout << -1;
	return 0;
}