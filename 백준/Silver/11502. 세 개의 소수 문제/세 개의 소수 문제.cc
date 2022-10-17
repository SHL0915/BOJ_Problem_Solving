#include <iostream>
#include <vector>
using namespace std;

int T, K;
int primeNum[1000];
vector <int> pNum;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int i = 2; i < 1000; i++) {
		if (primeNum[i] == 0) {
			pNum.push_back(i);
			for (int j = i * i; j < 1000; j += i) primeNum[j] = 1;
		}
	}
	for (int i = 0; i < T; i++) {
		cin >> K;
		int flag = 0;
		for (int j = 0; j < pNum.size(); j++) {
			if (flag == 1) break;
			for (int k = j; k < pNum.size(); k++) {
				if (K - pNum[j] - pNum[k] >= 2 && primeNum[K - pNum[j] - pNum[k]] == 0) {
					cout << pNum[j] << " " << pNum[k] << " " << K - pNum[j] - pNum[k] << "\n";
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) cout << 0 << "\n";
	}
	return 0;
}