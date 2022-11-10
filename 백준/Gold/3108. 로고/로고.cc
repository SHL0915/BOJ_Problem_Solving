#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, cnt;
int map[2001][2001];

void rec(int a, int b, int c, int d);
void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		rec((a + 500) * 2, (b + 500) * 2, (c + 500) * 2, (d + 500) * 2);
	}
	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= 2000; j++) {
			if (map[i][j] == 1) {
				cnt++;
				DFS(j, i);
			}
		}
	}
	if (map[1000][1000] == 2) cnt--;
	cout << cnt;
	return 0;
}

void rec(int a, int b, int c, int d) {
	for (int i = b; i <= d; i++) {
		map[i][a] = 1;
		map[i][c] = 1;
	}
	for (int i = a; i <= c; i++) {
		map[b][i] = 1;
		map[d][i] = 1;
	}
}

void DFS(int x, int y) {
	if (x < 0 || x > 2000 || y < 0 || y > 2000) return;
	if (map[y][x] == 0 || map[y][x] == 2) return;
	map[y][x] = 2;
	DFS(x - 1, y);
	DFS(x + 1, y);
	DFS(x, y - 1);
	DFS(x, y + 1);
	return;
}