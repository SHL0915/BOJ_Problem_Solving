#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long long mod = 123456789;

int N;
int table[40001];
long long dpTable[40001];
vector <int> primeNum;

int main(void) {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			for (int j = i * i; j <= N; j += i) table[j] = 1;
		}
	}
	dpTable[0] = 1;
	for (int i = 0; i < primeNum.size(); i++) {	
		for (int j = 1; j <= N; j++) {
			if (primeNum[i] > j) continue;
			else dpTable[j] = (dpTable[j] + dpTable[j - primeNum[i]]) % mod;
		}
	}
	cout << dpTable[N];
	return 0;
}
