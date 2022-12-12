#include <bits/stdc++.h>
using namespace std;

int N, M, ans, case_num;
int arr[30][30];

void BackTracking(int map[30][30], int dir, int x, int y, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> N >> M) {
		case_num++;
		ans = 1234567890;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < M; j++) {
				if (s[j] == '*') arr[i][j] = 1;
				else arr[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					for (int k = 0; k < 4; k++) {
						switch (k) {
						case 0: BackTracking(arr, k, j - 1, i, 1); break;
						case 1: BackTracking(arr, k, j + 1, i, 1); break;
						case 2: BackTracking(arr, k, j, i - 1, 1); break;
						case 3: BackTracking(arr, k, j, i + 1, 1); break;
						}
					}
					arr[i][j] = 0;
					cnt++;
				}
			}
		}
		cout << "Case " << case_num << ": ";
		if (cnt == 1) cout << 0 << '\n';
		else if (ans == 1234567890) cout << -1 << '\n';
		else cout << ans << '\n';
	}
	return 0;
}

void BackTracking(int map[30][30], int dir, int x, int y, int k) {
	int temp[30][30];
	int cnt = 0;
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (map[y][x] == 1) return;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) temp[i][j] = map[i][j];
	}
	if (dir == 0) {
		while (1) {
			if (x < 0) break;
			if (temp[y][x] == 1) break;
			temp[y][x] = 1;
			x--;
		}
		x++;
	}
	else if (dir == 1) {
		while (1) {
			if (x > M - 1) break;
			if (temp[y][x] == 1) break;
			temp[y][x] = 1;
			x++;
		}
		x--;
	}
	else if (dir == 2) {
		while (1) {
			if (y < 0) break;
			if (temp[y][x] == 1) break;
			temp[y][x] = 1;
			y--;
		}
		y++;
	}
	else {
		while (1) {
			if (y > N - 1) break;
			if (temp[y][x] == 1) break;
			temp[y][x] = 1;
			y++;
		}
		y--;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cnt += temp[i][j];
	}	
	if (cnt == N * M) {
		ans = min(ans, k);
		return;
	}
	for (int i = 0; i < 4; i++) {
		switch (i) {
		case 0: BackTracking(temp, i, x - 1, y, k + 1); break;
		case 1: BackTracking(temp, i, x + 1, y, k + 1); break;
		case 2: BackTracking(temp, i, x, y - 1, k + 1); break;
		case 3: BackTracking(temp, i, x, y + 1, k + 1); break;
		}
	}
}