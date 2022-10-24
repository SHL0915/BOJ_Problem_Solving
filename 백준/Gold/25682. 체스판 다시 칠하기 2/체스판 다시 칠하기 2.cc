#include <iostream>
using namespace std;

int N, M, K, ans = 4000000;
int board[2001][2001];
int psumA[2001][2001];
int psumB[2001][2001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			if (input[j] == 'B') board[i][j + 1] = 0;
			else board[i][j + 1] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					if (board[i][j] == 0) {
						psumA[i][j] = psumA[i - 1][j] + psumA[i][j - 1] - psumA[i - 1][j - 1] + 1;
						psumB[i][j] = psumB[i - 1][j] + psumB[i][j - 1] - psumB[i - 1][j - 1];
					}
					else {
						psumA[i][j] = psumA[i - 1][j] + psumA[i][j - 1] - psumA[i - 1][j - 1];
						psumB[i][j] = psumB[i - 1][j] + psumB[i][j - 1] - psumB[i - 1][j - 1] + 1;
					}
				}
				else {
					if (board[i][j] == 1) {
						psumA[i][j] = psumA[i - 1][j] + psumA[i][j - 1] - psumA[i - 1][j - 1] + 1;
						psumB[i][j] = psumB[i - 1][j] + psumB[i][j - 1] - psumB[i - 1][j - 1];
					}
					else {
						psumA[i][j] = psumA[i - 1][j] + psumA[i][j - 1] - psumA[i - 1][j - 1];
						psumB[i][j] = psumB[i - 1][j] + psumB[i][j - 1] - psumB[i - 1][j - 1] + 1;
					}
				}
			}
			else {
				if (j % 2 == 1) {
					if (board[i][j] == 0) {
						psumA[i][j] = psumA[i - 1][j] + psumA[i][j - 1] - psumA[i - 1][j - 1] + 1;
						psumB[i][j] = psumB[i - 1][j] + psumB[i][j - 1] - psumB[i - 1][j - 1];
					}
					else {
						psumA[i][j] = psumA[i - 1][j] + psumA[i][j - 1] - psumA[i - 1][j - 1];
						psumB[i][j] = psumB[i - 1][j] + psumB[i][j - 1] - psumB[i - 1][j - 1] + 1;
					}
				}
				else {
					if (board[i][j] == 1) {
						psumA[i][j] = psumA[i - 1][j] + psumA[i][j - 1] - psumA[i - 1][j - 1] + 1;
						psumB[i][j] = psumB[i - 1][j] + psumB[i][j - 1] - psumB[i - 1][j - 1];
					}
					else {
						psumA[i][j] = psumA[i - 1][j] + psumA[i][j - 1] - psumA[i - 1][j - 1];
						psumB[i][j] = psumB[i - 1][j] + psumB[i][j - 1] - psumB[i - 1][j - 1] + 1;
					}
				}
			}
		}
	}
	for (int i = 1; i <= N - K + 1; i++) {
		for (int j = 1; j <= M - K + 1; j++) {
			ans = min(ans, psumA[i + K - 1][j + K - 1] - psumA[i + K - 1][j - 1] - psumA[i - 1][j + K - 1] + psumA[i - 1][j - 1]);
			ans = min(ans, psumB[i + K - 1][j + K - 1] - psumB[i + K - 1][j - 1] - psumB[i - 1][j + K - 1] + psumB[i - 1][j - 1]);			
		}
	}
	cout << ans;
	return 0;
}