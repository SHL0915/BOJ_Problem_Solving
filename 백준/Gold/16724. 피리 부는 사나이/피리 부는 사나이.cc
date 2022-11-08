#include <iostream>
using namespace std;

int N, M, ans, cnt, flag;
char map[1000][1000];
int mark[1000][1000];

void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			map[i][j] = input[j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mark[i][j] == 0) {
				flag = 0;
				ans++;
				cnt++;
				DFS(j, i);
			}
		}
	}
	cout << ans;
	return 0;
}

void DFS(int x, int y) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (mark[y][x] != 0 && mark[y][x] != cnt && flag == 0) {
		ans--;
		flag = 1;
	}
	if (mark[y][x] != 0) return;
	mark[y][x] = cnt;
	switch (map[y][x]) {
	case 'U': DFS(x, y - 1); break;
	case 'D': DFS(x, y + 1); break;
	case 'L': DFS(x - 1, y); break;
	case 'R': DFS(x + 1, y); break;
	}
}