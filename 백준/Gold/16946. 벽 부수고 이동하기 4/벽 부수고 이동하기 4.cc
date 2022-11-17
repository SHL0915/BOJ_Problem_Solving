#include <iostream>
#include <set>
using namespace std;

int N, M, cnt, area;
int map[1000][1000];
int mark[1000][1000][3];
set <int> check;

void DFS(int x, int y);
void color(int x, int y, int c, int type);
int check_func(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) map[i][j] = input[j] - '0';
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && mark[i][j][0] == 0) {
				area++;
				cnt = 0;
				DFS(j, i);
				color(j, i, cnt, area);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) cout << 0;
			else {
				int ans = 0;
				check.clear();
				ans += check_func(j - 1, i);
				ans += check_func(j + 1, i);
				ans += check_func(j, i - 1);
				ans += check_func(j, i + 1);
				cout << (ans + 1) % 10;
			}
		}
		cout << '\n';
	}
	return 0;
}

void DFS(int x, int y) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (map[y][x] == 1) return;
	if (mark[y][x][0] != 0) return;
	mark[y][x][0] = 1;
	cnt++;
	DFS(x - 1, y);
	DFS(x + 1, y);
	DFS(x, y - 1);
	DFS(x, y + 1);
}

void color(int x, int y, int c, int type) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (map[y][x] == 1) return;
	if (mark[y][x][1] != 0) return;
	mark[y][x][1] = c;
	mark[y][x][2] = area;
	color(x - 1, y, c, type);
	color(x + 1, y, c, type);
	color(x, y - 1, c, type);
	color(x, y + 1, c, type);
}

int check_func(int x, int y) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return 0;
	if (map[y][x] == 1) return 0;
	if (check.count(mark[y][x][2]) != 0) return 0;
	check.insert(mark[y][x][2]);
	return mark[y][x][1];
}