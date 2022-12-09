#include <bits/stdc++.h>
using namespace std;

int N, M, cnt, flag, ans;
int arr[20][20];
int mark[20][20];

void BackTracking(int x, int y, int k);
void clear();
void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}
	BackTracking(0, 0, 0);
	cout << ans;
	return 0;
}

void BackTracking(int x, int y, int k) {
	if (k == 2) {
		clear();		
		int temp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (mark[i][j] == 0 && arr[i][j] == 2) {
					cnt = 0;
					flag = 0;
					DFS(j, i);
					if (flag == 0) temp += cnt;
				}
			}
		}
		ans = max(ans, temp);
		return;
	}

	if (x > M - 1 || y > N - 1) return;
	else {
		BackTracking((x + 1) % M, y + (x + 1) / M, k);
		if (arr[y][x] == 0) {
			arr[y][x] = 1;
			BackTracking((x + 1) % M, y + (x + 1) / M, k + 1);
			arr[y][x] = 0;
		}
	}
}

void clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) mark[i][j] = 0;
	}
}

void DFS(int x, int y) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (arr[y][x] == 0) {
		flag = 1;
		return;
	}
	if (arr[y][x] == 1) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	cnt++;
	DFS(x - 1, y);
	DFS(x + 1, y);
	DFS(x, y - 1);
	DFS(x, y + 1);
}