#include <iostream>
#include <queue>
using namespace std;

int R, C;
pair <int, int> s, e;
int map[50][50];
int mark[50][50];
queue<pair<int, int>> q;

void water();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < C; j++) {
			if (input[j] == 'D') {
				map[i][j] = 3;
				e = { j,i };
			}
			else if (input[j] == 'X') map[i][j] = 1;
			else if (input[j] == 'S') s = { j,i };
			else if (input[j] == '*') map[i][j] = 2;
		}
	}
	q.push({ s.first,s.second });
	int d = 1;
	while (q.size()) {
		queue <pair<int, int>> temp;		
		while (q.size()) {
			pair<int, int> f = q.front();
			q.pop();
			int x = f.first;
			int y = f.second;
			if (x < 0 || x > C - 1 || y < 0 || y > R - 1) continue;
			if (map[y][x] == 2 || map[y][x] == 1) continue;
			if (mark[y][x] != 0) continue;
			mark[y][x] = d;
			temp.push({ x + 1, y });
			temp.push({ x - 1, y });
			temp.push({ x, y + 1 });
			temp.push({ x, y - 1 });
		}
		while (temp.size()) {
			q.push(temp.front());
			temp.pop();
		}
		water();
		d++;
	}
	if (mark[e.second][e.first] == 0) cout << "KAKTUS";
	else cout << mark[e.second][e.first] - 1;
	return 0;
}

void water() {
	queue<pair<int, int>> w;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 2) {
				w.push({ j + 1,i });
				w.push({ j - 1,i });
				w.push({ j,i + 1 });
				w.push({ j,i - 1 });
			}
		}
	}
	while (w.size()) {
		pair<int, int> f = w.front();
		w.pop();
		int x = f.first;
		int y = f.second;
		if (x < 0 || x > C - 1 || y < 0 || y > R - 1) continue;
		if (map[y][x] == 3 || map[y][x] == 1) continue;
		map[y][x] = 2;
	}
}