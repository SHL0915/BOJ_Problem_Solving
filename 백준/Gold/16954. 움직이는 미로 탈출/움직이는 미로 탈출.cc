#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int wall_num;
int map[8][8];
int mark[8][8];
queue <pair<int, int>> q;

int wall();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 8; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < 8; j++) if (input[j] == '#') map[i][j] = 1;
	}
	q.push({ 0, 7 });
	while (q.size()) {
		queue<pair<int, int>> temp;
		while (q.size()) {
			pair<int, int> f = q.front();
			q.pop();
			int x = f.first;
			int y = f.second;
			if (x < 0 || x > 7 || y < 0 || y > 7) continue;
			if (map[y][x] == 1) continue;
			if (wall_num == 0 && mark[y][x] != 0) continue;
			if(wall_num == 0) mark[y][x] = 1;
			temp.push({ x,y });
			if (x > 0 && map[y][x - 1] != 1) temp.push({ x - 1, y });
			if (x < 7 && map[y][x + 1] != 1) temp.push({ x + 1, y });
			if (y > 0 && map[y - 1][x] != 1) temp.push({ x, y - 1 });
			if (y < 7 && map[y + 1][x] != 1) temp.push({ x, y + 1 });
			if (x > 0 && y > 0 && map[y - 1][x - 1] != 1) temp.push({ x - 1, y - 1 });
			if (x > 0 && y < 7 && map[y + 1][x - 1] != 1) temp.push({ x - 1, y + 1 });
			if (x < 7 && y > 0 && map[y - 1][x + 1] != 1) temp.push({ x + 1, y - 1 });
			if (x < 7 && y < 7 && map[y + 1][x + 1] != 1) temp.push({ x + 1, y + 1 });
		}
		wall_num = wall();
		while (temp.size()) {
			pair<int, int> f = temp.front();
			temp.pop();
			int x = f.first;
			int y = f.second;
			if (x < 0 || x > 7 || y < 0 || y > 7) continue;
			if (map[y][x] == 1) continue;
			q.push(f);
		}
	}
	if (mark[0][7] == 0) cout << 0;
	else cout << 1;
	return 0;
}

int wall() {
	queue <pair<int, int>> w;
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (map[i][j] == 1) {
				w.push({ j,i + 1 });
				map[i][j] = 0;
			}
		}
	}
	while (w.size()) {
		pair<int, int> f = w.front();
		w.pop();
		if (f.second > 7) continue;
		map[f.second][f.first] = 1;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (map[i][j] == 1) cnt++;
		}
	}
	return cnt;
}