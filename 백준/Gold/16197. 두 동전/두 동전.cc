#include <iostream>
#include <vector>
using namespace std;

int N, M, ans = 11;
char board[20][20];

void BackTracking(char parametric_board[20][20], int direction, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) board[i][j] = input[j];
	}
	BackTracking(board, 0, 1);
	BackTracking(board, 1, 1);
	BackTracking(board, 2, 1);
	BackTracking(board, 3, 1);
	if (ans == 11) cout << -1;
	else cout << ans;
	return 0;
}

void BackTracking(char parametric_board[20][20], int direction, int k) {
	if (k > 10) return;
	char temp[20][20];
	vector <pair<int, int>> coin;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) temp[i][j] = parametric_board[i][j];
	}
	if (direction == 0) { 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 'o') {
					temp[i][j] = '.';
					if (i == 0) continue;
					else if (temp[i - 1][j] == '#') coin.push_back({ i,j });
					else coin.push_back({ i - 1,j });
				}
			}
		}
	}
	else if (direction == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 'o') {
					temp[i][j] = '.';
					if (j == 0) continue;
					else if (temp[i][j - 1] == '#') coin.push_back({ i,j });
					else coin.push_back({ i,j - 1 });
				}
			}
		}
	}
	else if (direction == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 'o') {
					temp[i][j] = '.';
					if (i == N - 1) continue;
					else if (temp[i + 1][j] == '#') coin.push_back({ i,j });
					else coin.push_back({ i + 1,j });
				}
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 'o') {
					temp[i][j] = '.';
					if (j == M - 1) continue;
					else if (temp[i][j + 1] == '#') coin.push_back({ i,j });
					else coin.push_back({ i,j + 1 });
				}
			}
		}
	}
	if (coin.size() == 1) {
		ans = min(ans, k);
		return;
	}
	else if (coin.size() == 0) return;
	else if (coin[0].first == coin[1].first && coin[0].second == coin[1].second) return;
	else {
		temp[coin[0].first][coin[0].second] = 'o';
		temp[coin[1].first][coin[1].second] = 'o';
	}
	BackTracking(temp, 0, k + 1);
	BackTracking(temp, 1, k + 1);
	BackTracking(temp, 2, k + 1);
	BackTracking(temp, 3, k + 1);
	return;
}