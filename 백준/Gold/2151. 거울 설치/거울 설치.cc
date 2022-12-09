#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> piiii;

int N, cnt, ans = 1234567890;
int arr[50][50];
int mark[50][50][4];
pair<int, int> door[2];
queue <piiii> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == '*') arr[i][j] = 1;
			else if (s[j] == '!') arr[i][j] = 2;
			else if (s[j] == '#') door[cnt++] = { j,i };
		}
	}
	for(int i = 0; i < 4; i++) q.push({ {door[0].first, door[0].second}, {1,i} });
	while (q.size()) BFS();
	for (int i = 0; i < 4; i++) if (mark[door[1].second][door[1].first][i] != 0) ans = min(ans, mark[door[1].second][door[1].first][i] - 1);
	cout << ans;
	return 0;
}

void BFS() {
	piiii f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second.first;
	int dir = f.second.second;
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1) return;
	if (arr[y][x] == 1) return;
	if (mark[y][x][dir] != 0 && mark[y][x][dir] < d) return;
	mark[y][x][dir] = d;
	switch (dir) {
	case 0: q.push({ {x - 1,y},{d,dir} }); break;
	case 1: q.push({ {x + 1,y},{d,dir} }); break;
	case 2: q.push({ {x, y - 1},{d,dir} }); break;
	case 3: q.push({ {x, y + 1},{d,dir} }); break;
	}
	if (arr[y][x] == 2) {
		switch (dir) {
		case 0: q.push({ {x, y - 1},{d + 1, 2} }); q.push({ {x, y + 1},{d + 1, 3} }); break;
		case 1: q.push({ {x, y - 1},{d + 1, 2} }); q.push({ {x, y + 1},{d + 1, 3} }); break;
		case 2: q.push({ {x - 1, y},{d + 1, 0} }); q.push({ {x + 1, y},{d + 1, 1} }); break;
		case 3: q.push({ {x - 1, y},{d + 1, 0} }); q.push({ {x + 1, y},{d + 1, 1} }); break;
		}
	}
}