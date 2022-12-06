#include <bits/stdc++.h>
using namespace std;
const int N = 5;
typedef pair<pair<pair<int, int>, int>, int> piiii;

int ans = 1234567890;
int org[5][5][5];
int cube[5][5][5];
int temp[5][5];
int bt[5];
int mark[5];
int visited[5][5][5];
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
queue <piiii> q;

void BackTracking(int k);
void makeCube(int k);
void rotate();
void BFS();
void clear();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) cin >> org[i][j][k];
		}
	}
	BackTracking(0);
	if (ans == 1234567890) cout << -1;
	else cout << ans;
	return 0;
}

void BackTracking(int k) {
	if (k == N) makeCube(0);
	else {
		for (int i = 0; i < N; i++) {
			if (mark[i] == 0) {
				mark[i] = 1;
				bt[k] = i;
				BackTracking(k + 1);
				mark[i] = 0;
			}
		}
	}
}

void makeCube(int k) {
	if (k == N) {
		clear();
		q.push({ {{0,0},0},1 });
		while (q.size()) BFS();
		if (visited[4][4][4] == 0) return;
		else ans = min(ans, visited[4][4][4] - 1);		
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) temp[i][j] = org[bt[k]][i][j];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cube[k][i][j] = temp[i][j];
		}
		makeCube(k + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) temp[i][j] = org[bt[k]][i][j];
		}
		rotate();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cube[k][i][j] = temp[i][j];
		}
		makeCube(k + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) temp[i][j] = org[bt[k]][i][j];
		}
		rotate();
		rotate();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cube[k][i][j] = temp[i][j];
		}
		makeCube(k + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) temp[i][j] = org[bt[k]][i][j];
		}
		rotate();
		rotate();
		rotate();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cube[k][i][j] = temp[i][j];
		}
		makeCube(k + 1);
	}
}

void rotate() {
	int ntemp[5][5];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) ntemp[j][N - 1 - i] = temp[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) temp[i][j] = ntemp[i][j];
	}
}

void clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) visited[i][j][k] = 0;
		}
	}
}

void BFS() {
	piiii f = q.front();
	q.pop();
	int x = f.first.first.first;
	int y = f.first.first.second;
	int z = f.first.second;
	int d = f.second;
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1 || z < 0 || z > N - 1) return;
	if (cube[z][y][x] == 0) return;
	if (visited[z][y][x] != 0) return;
	visited[z][y][x] = d;
	for (int i = 0; i < 6; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int nz = z + dz[i];
		q.push({ {{nx, ny},nz},d + 1 });
	}
}