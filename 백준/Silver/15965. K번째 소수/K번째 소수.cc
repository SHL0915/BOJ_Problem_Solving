#include <iostream>
#include <vector>
using namespace std;

int primeNum[20000000];
int K;
vector <int> pNum;

int main(void) {
	cin >> K;
	for (long long i = 2; i < 20000000; i++) {
		if (primeNum[i] == 0) {
			pNum.push_back(i);
			for (long long j = i * i; j < 20000000; j += i) primeNum[j] = 1;
		}
	}
	cout << pNum[K - 1];
	return 0;
}