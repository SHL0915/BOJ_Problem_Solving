#include <iostream>
using namespace std;

int N, M, ans = 11;

void BackTracking(char prev_board[10][10], int number, int operation, pair <int, int> red, pair <int, int> blue);

int main(void) {
	cin >> N >> M;
	char board[10][10];
	pair <int, int> r_pos, b_pos;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			board[i][j] = s[j];
			if (s[j] == 'R') r_pos = { j,i };
			if (s[j] == 'B') b_pos = { j,i };
		}
	}
	for (int i = 0; i < 4; i++)
		BackTracking(board, 0, i, r_pos, b_pos);
	if (ans == 11)
		cout << -1;
	else
		cout << ans;
	return 0;
}

void BackTracking(char prev_board[10][10], int number, int operation, pair <int, int> red, pair <int, int> blue) {
	if (number == 10)
		return;
	int flag = 0;
	pair <int, int> red_pos, blue_pos;
	char temp[10][10];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			temp[i][j] = prev_board[i][j];
	if (operation == 0) { // 왼쪽으로 기울이기
		if (red.first <= blue.first) {
			for (int i = red.first - 1; i >= 0; i--) {
				if (temp[red.second][i] == 'O') {
					temp[red.second][red.first] = '.';
					flag = 1;
					break;
				}
				else if (temp[red.second][i] != '.') {
					temp[red.second][red.first] = '.';
					temp[red.second][i + 1] = 'R';
					red_pos = { i + 1, red.second };
					break;
				}
			}
			for (int i = blue.first - 1; i >= 0; i--) {
				if (temp[blue.second][i] == 'O') {
					return;
				}
				else if (temp[blue.second][i] != '.') {
					temp[blue.second][blue.first] = '.';
					temp[blue.second][i + 1] = 'B';
					blue_pos = { i + 1, blue.second };
					break;
				}
			}
		}
		else {
			for (int i = blue.first - 1; i >= 0; i--) {
				if (temp[blue.second][i] == 'O') {
					return;
				}
				else if (temp[blue.second][i] != '.') {
					temp[blue.second][blue.first] = '.';
					temp[blue.second][i + 1] = 'B';
					blue_pos = { i + 1, blue.second };
					break;
				}
			}
			for (int i = red.first - 1; i >= 0; i--) {
				if (temp[red.second][i] == 'O') {
					temp[red.second][red.first] = '.';
					flag = 1;
					break;
				}
				else if (temp[red.second][i] != '.') {
					temp[red.second][red.first] = '.';
					temp[red.second][i + 1] = 'R';
					red_pos = { i + 1, red.second };
					break;
				}
			}
		}
	}
	else if (operation == 1) { // 오른쪽으로 기울이기
		if (red.first >= blue.first) {
			for (int i = red.first + 1; i < M; i++) {
				if (temp[red.second][i] == 'O') {
					temp[red.second][red.first] = '.';
					flag = 1;
					break;
				}
				else if (temp[red.second][i] != '.') {
					temp[red.second][red.first] = '.';
					temp[red.second][i - 1] = 'R';
					red_pos = { i - 1, red.second };
					break;
				}
			}
			for (int i = blue.first + 1; i < M; i++) {
				if (temp[blue.second][i] == 'O') {
					return;
				}
				else if (temp[blue.second][i] != '.') {
					temp[blue.second][blue.first] = '.';
					temp[blue.second][i - 1] = 'B';
					blue_pos = { i - 1, blue.second };
					break;
				}
			}
		}
		else {
			for (int i = blue.first + 1; i < M; i++) {
				if (temp[blue.second][i] == 'O') {
					return;
				}
				else if (temp[blue.second][i] != '.') {
					temp[blue.second][blue.first] = '.';
					temp[blue.second][i - 1] = 'B';
					blue_pos = { i - 1, blue.second };
					break;
				}
			}
			for (int i = red.first + 1; i < M; i++) {
				if (temp[red.second][i] == 'O') {
					temp[red.second][red.first] = '.';
					flag = 1;
					break;
				}
				else if (temp[red.second][i] != '.') {
					temp[red.second][red.first] = '.';
					temp[red.second][i - 1] = 'R';
					red_pos = { i - 1, red.second };
					break;
				}
			}
		}
	}
	else if (operation == 2) { // 위쪽으로 기울이기
		if (red.second <= blue.second) {
			for (int i = red.second - 1; i >= 0; i--) {
				if (temp[i][red.first] == 'O') {
					temp[red.second][red.first] = '.';
					flag = 1;
					break;
				}
				else if (temp[i][red.first] != '.') {
					temp[red.second][red.first] = '.';
					temp[i + 1][red.first] = 'R';
					red_pos = { red.first , i + 1 };
					break;
				}
			}
			for (int i = blue.second - 1; i >= 0; i--) {
				if (temp[i][blue.first] == 'O') {
					return;
				}
				else if (temp[i][blue.first] != '.') {
					temp[blue.second][blue.first] = '.';
					temp[i + 1][blue.first] = 'B';
					blue_pos = { blue.first , i + 1 };
					break;
				}
			}
		}
		else {
			for (int i = blue.second - 1; i >= 0; i--) {
				if (temp[i][blue.first] == 'O') {
					return;
				}
				else if (temp[i][blue.first] != '.') {
					temp[blue.second][blue.first] = '.';
					temp[i + 1][blue.first] = 'B';
					blue_pos = { blue.first , i + 1 };
					break;
				}
			}
			for (int i = red.second - 1; i >= 0; i--) {
				if (temp[i][red.first] == 'O') {
					temp[red.second][red.first] = '.';
					flag = 1;
					break;
				}
				else if (temp[i][red.first] != '.') {
					temp[red.second][red.first] = '.';
					temp[i + 1][red.first] = 'R';
					red_pos = { red.first , i + 1 };
					break;
				}
			}
		}
	}
	else { // 아래쪽으로 기울이기
		if (red.second >= blue.second) {
			for (int i = red.second + 1; i < N; i++) {
				if (temp[i][red.first] == 'O') {
					temp[red.second][red.first] = '.';
					flag = 1;
					break;
				}
				else if (temp[i][red.first] != '.') {
					temp[red.second][red.first] = '.';
					temp[i - 1][red.first] = 'R';
					red_pos = { red.first , i - 1 };
					break;
				}
			}
			for (int i = blue.second + 1; i < N; i++) {
				if (temp[i][blue.first] == 'O') {
					return;
				}
				else if (temp[i][blue.first] != '.') {
					temp[blue.second][blue.first] = '.';
					temp[i - 1][blue.first] = 'B';
					blue_pos = { blue.first , i - 1 };
					break;
				}
			}
		}
		else {
			for (int i = blue.second + 1; i < N; i++) {
				if (temp[i][blue.first] == 'O') {
					return;
				}
				else if (temp[i][blue.first] != '.') {
					temp[blue.second][blue.first] = '.';
					temp[i - 1][blue.first] = 'B';
					blue_pos = { blue.first , i - 1 };
					break;
				}
			}
			for (int i = red.second + 1; i < N; i++) {
				if (temp[i][red.first] == 'O') {
					temp[red.second][red.first] = '.';
					flag = 1;
					break;
				}
				else if (temp[i][red.first] != '.') {
					temp[red.second][red.first] = '.';
					temp[i - 1][red.first] = 'R';
					red_pos = { red.first , i - 1 };
					break;
				}
			}
		}
	}
	if (flag == 1) {
		ans = min(ans, number + 1);
		return;
	}
	else {
		for (int i = 0; i < 4; i++)
			BackTracking(temp, number + 1, i, red_pos, blue_pos);
	}
}