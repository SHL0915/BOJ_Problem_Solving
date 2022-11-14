#include <iostream>
using namespace std;

string board;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> board;
	for (int i = 0; i < board.length(); i++) {
		if (board[i] != 'X') continue;
		int cnt = 0;
		int ptr = i;
		for (int j = i; j < board.length(); j++) {
			if (board[j] == 'X') cnt++;
			else break;
		}
		if (cnt % 2 == 1) {
			cout << -1;
			return 0;
		}
		for (int j = 0; j < cnt / 4; j++) {
			for (int k = 0; k < 4; k++, ptr++) {
				board[ptr] = 'A';
			}
		}
		for (int j = 0; j < (cnt%4) / 2; j++) {
			for (int k = 0; k < 2; k++, ptr++) {
				board[ptr] = 'B';
			}
		}
	}
	cout << board;
	return 0;
}