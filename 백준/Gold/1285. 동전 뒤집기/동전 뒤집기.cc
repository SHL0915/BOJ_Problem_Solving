#include <iostream>
#include <algorithm>
using namespace std;

int N, minNum = 0;
int coins[20][20];
int temp1[20][20];
int temp2[20][20];

void FlipRow(int bit);
void FlipColumn();

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'H') coins[i][j] = 0;
			else {
				coins[i][j] = 1;
				minNum++;
			}
		}
	}
	int last = (1 << N);
	for (int i = 0; i < last; i++) {
		int bit = i;
		FlipRow(bit);
	}
	cout << minNum;
	return 0;
}

void FlipRow(int bit) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp1[i][j] = coins[i][j];
		}
	}
	int row = 0;
	while (bit) {
		if (bit & 1) {
			for (int i = 0; i < N; i++) {
				temp1[row][i] += 1;
				temp1[row][i] %= 2;
			}
		}
		bit = bit >> 1;
		row++;
	}
	FlipColumn();
	return;
}

void FlipColumn() {
	int sum;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp2[i][j] = temp1[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		sum = 0;
		for (int j = 0; j < N; j++)
			sum += temp2[j][i];
		if (sum > N / 2) {
			for (int j = 0; j < N; j++) {
				temp2[j][i] += 1;
				temp2[j][i] %= 2;
			}
		}		
	}
	sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			sum += temp2[i][j];		
	}
	minNum = min(minNum, sum);
	return;
}