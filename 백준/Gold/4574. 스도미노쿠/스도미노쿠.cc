#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 1234567890;

int N, p_num, flag;
set <pair<int, int>> domino;
int board[10][10];
vector <pair<int, int>> pos;

void BackTracking(int x, int y, int idx);
bool check(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> N;
		if (N == 0) break;
		flag = 0;
		p_num++;
		domino.clear();
		pos.clear();
		for (int i = 1; i <= 9; i++) {
			for (int j = i + 1; j <= 9; j++) domino.insert({ i,j });
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) board[i][j] = 0;
		}
		for (int i = 0; i < 10; i++) {
			board[9][i] = 1;
			board[i][9] = 1;
		}
		for (int i = 0; i < N; i++) {
			int U, V;
			string LU, LV;
			cin >> U >> LU >> V >> LV;
			domino.erase({ min(U,V), max(U,V) });
			board[LU[0] - 'A'][LU[1] - '1'] = U;
			board[LV[0] - 'A'][LV[1] - '1'] = V;
		}
		for (int i = 1; i <= 9; i++) {
			string s;
			cin >> s;
			board[s[0] - 'A'][s[1] - '1'] = i;
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) if (board[i][j] == 0) pos.push_back({ j,i });
		}		
		pos.push_back({ INF,INF });		
		BackTracking(pos[0].first, pos[0].second, 0);
	}
	return 0;
}

void BackTracking(int x, int y, int idx) {
	if (flag == 1) return;
	if (idx == pos.size() - 1) {
		cout << "Puzzle " << p_num << '\n';
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) cout << board[i][j];
			cout << '\n';
		}
		flag = 1;
		return;
	}
	else {
		if (board[y][x] != 0) {
			BackTracking(pos[idx + 1].first, pos[idx + 1].second, idx + 1);
			return;
		}
		if (board[y][x + 1] == 0) {
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					if (domino.count({ min(i,j),max(i,j) }) != 0) {
						board[y][x] = i;
						board[y][x + 1] = j;
						if (check(x, y) == true && check(x + 1, y) == true) {
							domino.erase({ min(i,j),max(i,j) });
							BackTracking(pos[idx + 1].first, pos[idx + 1].second, idx + 1);
							domino.insert({ min(i,j),max(i,j) });
						}
						board[y][x] = 0;
						board[y][x + 1] = 0;
					}
				}
			}
		}
		if (board[y + 1][x] == 0) {
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					if (domino.count({ min(i,j),max(i,j) }) != 0) {
						board[y][x] = i;
						board[y + 1][x] = j;
						if (check(x, y) == true && check(x, y + 1) == true) {
							domino.erase({ min(i,j),max(i,j) });
							BackTracking(pos[idx + 1].first, pos[idx + 1].second, idx + 1);
							domino.insert({ min(i,j),max(i,j) });
						}
						board[y][x] = 0;
						board[y + 1][x] = 0;
					}
				}
			}
		}	
	}
}

bool check(int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (i != x && board[y][x] == board[y][i]) return false;
		if (i != y && board[y][x] == board[i][x]) return false;
	}		
	int x_base = (x / 3) * 3;
	int y_base = (y / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (x_base + j == x && y_base + i == y) continue;
			if (board[y_base + i][x_base + j] == board[y][x]) return false;
		}
	}
	return true;
}