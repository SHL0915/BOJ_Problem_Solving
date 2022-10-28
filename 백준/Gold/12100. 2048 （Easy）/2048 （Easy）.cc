#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int board[20][20][2];

void BackTracking(int arr[20][20][2], int k, int direction);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> board[i][j][0];
	}
	BackTracking(board, 1, 0);
	BackTracking(board, 1, 1);
	BackTracking(board, 1, 2);
	BackTracking(board, 1, 3);
	cout << ans;
	return 0;
}

void BackTracking(int arr[20][20][2], int k, int direction) {
	int temp[20][20][2];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j][0] = arr[i][j][0];
			temp[i][j][1] = 0;
		}
	}
	if (direction == 0) {
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int pos = i;
				int val = temp[i][j][0];
				temp[i][j][0] = 0;
				while (pos > 0) {
					if (temp[pos][j][0] != 0) break;					
					pos--;
				}
				if (temp[pos][j][0] == 0) temp[pos][j][0] = val;
				else if (temp[pos][j][0] == val && temp[pos][j][1] == 0) {
					temp[pos][j][0] *= 2;
					temp[pos][j][1] = 1;
				}
				else temp[pos + 1][j][0] = val;
			}
		}
	}
	else if (direction == 1) {
		for (int i = N - 2; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				int pos = i;
				int val = temp[i][j][0];
				temp[i][j][0] = 0;
				while (pos < N - 1) {
					if (temp[pos][j][0] != 0) break;
					pos++;
				}
				if (temp[pos][j][0] == 0) temp[pos][j][0] = val;
				else if (temp[pos][j][0] == val && temp[pos][j][1] == 0) {
					temp[pos][j][0] *= 2;
					temp[pos][j][1] = 1;
				}
				else temp[pos - 1][j][0] = val;
			}
		}
	}
	else if (direction == 2) {
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int pos = i;
				int val = temp[j][i][0];
				temp[j][i][0] = 0;
				while (pos > 0) {
					if (temp[j][pos][0] != 0) break;					
					pos--;
				}
				if (temp[j][pos][0] == 0) temp[j][pos][0] = val;
				else if (temp[j][pos][0] == val && temp[j][pos][1] == 0) {
					temp[j][pos][0] *= 2;
					temp[j][pos][1] = 1;
				}
				else temp[j][pos + 1][0] = val;
			}
		}
	}
	else {
		for (int i = N - 2; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				int pos = i;
				int val = temp[j][i][0];
				temp[j][i][0] = 0;
				while (pos < N - 1) {
					if (temp[j][pos][0] != 0) break;					
					pos++;
				}
				if (temp[j][pos][0] == 0) temp[j][pos][0] = val;
				else if (temp[j][pos][0] == val && temp[j][pos][1] == 0) {
					temp[j][pos][0] *= 2;
					temp[j][pos][1] = 1;
				}
				else temp[j][pos - 1][0] = val;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) ans = max(ans, temp[i][j][0]);			
	}
	if (k == 5) return;
	else {
		BackTracking(temp, k + 1, 0);
		BackTracking(temp, k + 1, 1);
		BackTracking(temp, k + 1, 2);
		BackTracking(temp, k + 1, 3);
	}
	return;
}