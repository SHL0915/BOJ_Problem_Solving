#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
string word;
vector <pair<int, int>> start;
char board[100][100];
long long table[100][100][81];
long long ans;

long long DP(int x, int y, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) board[i][j] = input[j];
	}
	cin >> word;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == word[word.length() - 1]) start.push_back({ j,i });
		}
	}
	for (int i = 0; i < start.size(); i++) ans += DP(start[i].first, start[i].second, word.length() - 1);		
	cout << ans;
	return 0;
}

long long DP(int x, int y, int k) {
	if (k == 0) return 1;
	else if (table[x][y][k] != 0) return table[x][y][k];
	else {
		for (int i = 1; i <= K; i++) {
			if (x - i >= 0 && board[y][x - i] == word[k - 1]) table[x][y][k] += DP(x - i, y, k - 1);
			if (x + i < M && board[y][x + i] == word[k - 1]) table[x][y][k] += DP(x + i, y, k - 1);
			if (y - i >= 0 && board[y - i][x] == word[k - 1]) table[x][y][k] += DP(x, y - i, k - 1);
			if (y + i < N && board[y + i][x] == word[k - 1]) table[x][y][k] += DP(x, y + i, k - 1);
		}
		return table[x][y][k];
	}
}