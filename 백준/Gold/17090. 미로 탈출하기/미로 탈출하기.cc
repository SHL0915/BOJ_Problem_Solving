#include <bits/stdc++.h>
using namespace std;

int N, M, area, flag, cnt;
char arr[500][500];
int mark[500][500];
int check[500][500];

void DFS(int x, int y, int color);
void color(int x, int y, int area);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) arr[i][j] = s[j];		
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mark[i][j] == 0) {
				flag = 0;
				area++;
				DFS(j, i, area);
				if (flag == 1) color(j, i, area);				
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cnt += check[i][j];
	}
	cout << cnt;
	return 0;
}

void DFS(int x, int y, int color) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) {
		flag = 1;
		return;
	}
	if (mark[y][x] != 0) {
		if (check[y][x] == 1) flag = 1;		
		return;
	}
	mark[y][x] = color;
	switch (arr[y][x]) {
	case 'U': DFS(x, y - 1, color); break;
	case 'R': DFS(x + 1, y, color); break;
	case 'D': DFS(x, y + 1, color); break;
	case 'L': DFS(x - 1, y, color); break;
	}
}

void color(int x, int y, int area) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (mark[y][x] != area) return;
	check[y][x] = 1;
	switch (arr[y][x]) {
	case 'U': color(x, y - 1, area); break;
	case 'R': color(x + 1, y, area); break;
	case 'D': color(x, y + 1, area); break;
	case 'L': color(x - 1, y, area); break;
	}
}