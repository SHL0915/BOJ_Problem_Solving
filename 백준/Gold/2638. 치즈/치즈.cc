#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M, t;
int arr[101][101];
int mark[101][101];

void DFS(int x, int y);
int check(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}
	DFS(0, 0);
	while (1) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sum += arr[i][j];
			}
		}
		if (sum == 0) break;
		t++;
		vector <pair<int, int>> list;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1) {
					int ch = 0;
					for (int k = 0; k < 4; k++) {
						int nx = j + dx[k];
						int ny = i + dy[k];
						ch += check(nx, ny);
					}
					if (ch >= 2) {
						arr[i][j] = 0;
						list.push_back({ j,i });
					}
				}
			}
		}
		for (int i = 0; i < list.size(); i++) DFS(list[i].first, list[i].second);
	}
	cout << t;
	return 0;
}

void DFS(int x, int y) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (arr[y][x] == 1) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		DFS(nx, ny);
	}
	return;
}

int check(int x, int y) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return 1;	
	if (mark[y][x] == 1) return 1;
	else return 0;
}