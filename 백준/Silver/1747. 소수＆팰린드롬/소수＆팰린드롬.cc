#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int table[50000001];
vector <int> primeNum;

bool check(int A);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (long long i = 2; i <= 10000000; i++) {
		if (table[i] == 0) {
			table[i] = 1;
			primeNum.push_back(i);
			for (long long j = i * i; j <= 10000000; j += i) table[j] = 1;
		}
	}
	int pos = lower_bound(primeNum.begin(), primeNum.end(), N) - primeNum.begin();
	for (; pos < primeNum.size(); pos++) {
		if (check(primeNum[pos]) == true) {
			cout << primeNum[pos];
			return 0;
		}
	}
	return 0;
}

bool check(int A) {
	string temp = "";
	int degree = 10;
	while (A) {
		temp += (A % degree + '0');
		A /= 10;
	}
	for (int i = 0; i < temp.length() / 2; i++) {
		if (temp[i] != temp[temp.length() - 1 - i]) return false;
	}
	return true;
}