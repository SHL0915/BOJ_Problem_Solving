#include <iostream>
#include <algorithm>
using namespace std;

int N, alphIndex, ans;
string words[10];
int Alphabet[26];
int AlphNum[10];
int mark[10];

int calculate();
void BackTracking(int k);


int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> words[i];
		for (int j = 0; j < words[i].length(); j++) {
			if (Alphabet[words[i][j] - 'A'] == 0) {
				AlphNum[alphIndex++] = words[i][j] - 'A';
				Alphabet[words[i][j] - 'A'] = 1;
			}
		}
	}
	BackTracking(0);
	cout << ans;
	return 0;
}

int calculate() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int num = 0;
		int temp = 1;
		for (int j = 0; j < words[i].length(); j++) {
			num += Alphabet[words[i][words[i].length() - 1 - j] - 'A'] * temp;
			temp *= 10;
		}
		sum += num;
	}
	return sum;
}

void BackTracking(int k) {
	if (k == alphIndex) {
		ans = max(ans, calculate());
		return;
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (mark[i] == 0) {
				mark[i] = 1;
				Alphabet[AlphNum[k]] = i;
				BackTracking(k + 1);
				mark[i] = 0;
			}
		}
	}
}