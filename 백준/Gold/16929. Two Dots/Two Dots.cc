#include <iostream>
#include <vector>
using namespace std;

int N, M;
int mark[50][50] = {0};
char board[50][50];

void DFS(pair<int, int> org, pair<int, int> vertex, char Color, int depth);
void ClearMark();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			board[i][j] = input[j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ClearMark();
			DFS(make_pair(i, j), make_pair(i, j), board[i][j], 0);
		}
	}
	cout << "No";
	return 0;
}

void DFS(pair<int, int> org, pair<int, int> vertex, char Color, int depth) {
	if (mark[vertex.first][vertex.second] == 1) {
		if (vertex == org) {
			if (depth > 2) {
				cout << "Yes";
				exit(0);
			}
		}
		return;
	}
	mark[vertex.first][vertex.second] = 1;
	char val = board[vertex.first][vertex.second];
	if (vertex.first > 0 && board[vertex.first - 1][vertex.second] == val) 
		DFS(org, make_pair(vertex.first - 1, vertex.second), val, depth + 1);
	if (vertex.second > 0 && board[vertex.first][vertex.second - 1] == val)
		DFS(org, make_pair(vertex.first, vertex.second - 1), val, depth + 1);
	if (vertex.first < N-1 && board[vertex.first + 1][vertex.second] == val)
		DFS(org, make_pair(vertex.first + 1, vertex.second), val, depth + 1);
	if (vertex.second < M-1 && board[vertex.first][vertex.second + 1] == val)
		DFS(org, make_pair(vertex.first, vertex.second + 1), val, depth + 1);
	return;
}

void ClearMark() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			mark[i][j] = 0;
	}
	return;
}