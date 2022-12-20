#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> piii;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M, ans;
int arr[51][51];
int mark[51][51];
queue <piii> q;

void BFS();
void check();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == 'W') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				memset(mark, 0, sizeof(mark));
				q.push({ {j,i},1 });
				while (q.size()) BFS();
				check();
			}
		}
	}
	cout << ans;
	return 0;
}

void BFS() {
	piii f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second;
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (arr[y][x] == 1) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = d;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		q.push({ {nx,ny},d + 1 });
	}
}

void check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) ans = max(ans, mark[i][j] - 1);
	}
}