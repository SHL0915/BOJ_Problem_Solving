#include <iostream>
using namespace std;

int N, M, wSum, bSum, sum;
char field[100][100];
int mark[100][100];

void DFS(int x, int y, char color);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) field[i][j] = input[j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mark[i][j] == 0) {
				sum = 0;
				if (field[i][j] == 'W') {
					DFS(j, i, 'W');
					wSum += sum * sum;
				}
				else {
					DFS(j, i, 'B');
					bSum += sum * sum;
				}
			}
		}
	}
	cout << wSum << " " << bSum;
	return 0;
}

void DFS(int x, int y, char color) {
	if (field[y][x] != color) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	sum++;
	if (x > 0) DFS(x - 1, y, color);
	if (x < M - 1) DFS(x + 1, y, color);
	if (y > 0) DFS(x, y - 1, color);
	if (y < N - 1) DFS(x, y + 1, color);
	return;
}