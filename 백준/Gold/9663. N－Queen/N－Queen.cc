#include <iostream>
using namespace std;

int N, num = 0;
int chessboard[14][14] = { 0 };

void N_Queen(int k);
bool CanPutQueen(int x, int y);

int main(void) {
	cin >> N;
	N_Queen(0);
	cout << num;
	return 0;
}

void N_Queen(int k) {
	if (k == N) {
		num++;		
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (CanPutQueen(i, k) == true) {
				chessboard[k][i] = 1;
				N_Queen(k + 1);
				chessboard[k][i] = 0;
			}
		}
	}
}

bool CanPutQueen(int x, int y) {
	int i;
	for (i = 0; i < y; i++) {
		if (chessboard[i][x] == 1)
			return false;
	}
	i = 0;
	while (1) {
		if (x - i < 0 || y - i < 0)
			break;
		if (chessboard[y - i][x - i] == 1)
			return false;
		i++;
	}
	i = 0;
	while (1) {
		if (x + i >= N || y - i < 0)
			break;
		if (chessboard[y - i][x + i] == 1)
			return false;
		i++;
	}
	return true;
}