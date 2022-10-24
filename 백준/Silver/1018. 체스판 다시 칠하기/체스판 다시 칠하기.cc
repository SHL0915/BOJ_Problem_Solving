#include <iostream>
using namespace std;

int N, M, ans = 64;
int board[50][50];
int A[8][8];
int B[8][8];

void FillA();
void FillB();
int compare(int x, int y, int type[8][8]);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	FillA();
	FillB();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			if (input[j] == 'W') board[i][j] = 0;
			else board[i][j] = 1;
		}
	}
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			ans = min(ans, compare(j, i, A));
			ans = min(ans, compare(j, i, B));
		}
	}
	cout << ans;
	return 0;
}

void FillA() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) A[i][j] = 0;
				else A[i][j] = 1;
			}
			else {
				if (j % 2 == 0) A[i][j] = 1;
				else A[i][j] = 0;
			}
		}
	}
}

void FillB() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) B[i][j] = 1;
				else B[i][j] = 0;
			}
			else {
				if (j % 2 == 0) B[i][j] = 0;
				else B[i][j] = 1;
			}
		}
	}
}

int compare(int x, int y, int type[8][8]) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[y + i][x + j] != type[i][j]) cnt++;
		}
	}
	return cnt;
}