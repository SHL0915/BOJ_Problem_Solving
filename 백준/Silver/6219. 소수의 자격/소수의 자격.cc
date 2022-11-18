#include <iostream>
#include <vector>
using namespace std;

int A, B, D, cnt;
int table[4000001];
vector <int> primeNum;

bool check(int N);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> D;
	for (long long i = 2; i <= B; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			table[i] = 1;
			for (long long j = i * i; j <= B; j += i) table[j] = 1;
		}
	}
	for (int i = 0; i < primeNum.size(); i++) {
		if (primeNum[i] < A) continue;
		if (check(primeNum[i]) == true) cnt++;
	}
	cout << cnt;
	return 0;
}

bool check(int N) {
	while (N) {
		if (N % 10 == D) return true;
		N /= 10;
	}
	return false;
}