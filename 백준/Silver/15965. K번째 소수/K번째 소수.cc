#include <iostream>
#include <vector>
using namespace std;

int primeNum[7368788];
int K;
vector <int> pNum;

int main(void) {
	cin >> K;
	for (long long i = 2; i < 7368788; i++) {
		if (primeNum[i] == 0) {
			pNum.push_back(i);
			for (long long j = i * i; j < 7368788; j += i) primeNum[j] = 1;
		}
	}
	cout << pNum[K - 1];
	return 0;
}