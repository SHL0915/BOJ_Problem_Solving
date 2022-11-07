#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[100][100];
int mark[100][100];
queue <pair<pair<int, int>, int>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) if (input[j] == '1') map[i][j] = 1;		
	}
	q.push({ {0,0},1 });
	while (q.size()) BFS();
	return 0;
}

void BFS() {
	pair<pair<int, int>, int> temp = q.front();
	q.pop();
	int x = temp.first.first;
	int y = temp.first.second;
	int d = temp.second;
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (map[y][x] == 0) return;
	if (x == M - 1 && y == N - 1) {
		cout << d;
		exit(0);
	}
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	q.push({ {x + 1,y},d + 1 });
	q.push({ {x - 1,y},d + 1 });
	q.push({ {x,y + 1},d + 1 });
	q.push({ {x,y - 1},d + 1 });
	return;
}