#include <iostream>
using namespace std;

int R, C, ans;
char board[20][20];

void DFS(int x, int y, int mark[26], int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int mark[26] = { 0 };
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < C; j++) board[i][j] = input[j];
	}	
	DFS(0, 0, mark, 1);
	cout << ans;
	return 0;
}


void DFS(int x, int y, int mark[26], int k) {
	if (mark[board[y][x] - 'A'] != 0) return;
	int temp[26];
	for (int i = 0; i < 26; i++) temp[i] = mark[i];
	temp[board[y][x] - 'A'] = 1;
	ans = max(ans, k);
	if (x > 0) DFS(x - 1, y, temp, k + 1);
	if (x < C - 1) DFS(x + 1, y, temp, k + 1);
	if (y > 0) DFS(x, y - 1, temp, k + 1);
	if (y < R - 1) DFS(x, y + 1, temp, k + 1);
	return;
}