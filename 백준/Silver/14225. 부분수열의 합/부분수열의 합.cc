#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, i, j;
int S[20];
vector <int> sumList;

int main(void) {
	cin >> N;
	for (i = 0; i < N; i++) 
		cin >> S[i];
	for (i = 1; i < (1 << N); i++) {
		int sum = 0;
		int bit = 1;
		for (j = 0; j < N; j++) {
			if (bit & i) 
				sum += S[j];
			bit = bit << 1;
		}	
		sumList.push_back(sum);
	}
	sort(sumList.begin(), sumList.end());	
	if (sumList.front() > 1)
		cout << 1;
	else {
		for (i = 1; i < sumList.size(); i++) {
			if (sumList[i] - sumList[i - 1] > 1) {
				cout << sumList[i - 1] + 1;
				break;
			}
		}
		if (i == sumList.size())
			cout << sumList.back() + 1;
	}
	return 0;
}