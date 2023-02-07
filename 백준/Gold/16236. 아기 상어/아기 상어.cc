#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, start_x, start_y, s = 2, t, cnt, flag;
int map[20][20];
int mark[20][20];
queue <pair<pair<int, int>, int>> q;
vector <pair<int, int>> fish;

void BFS();

bool cmp(pair<int, int> A, pair<int, int> B) {
	if (A.second == B.second) return A.first < B.first;
	return A.second < B.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				start_x = j;
				start_y = i;
			}
		}
	}
	while (1) {
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) mark[i][j] = 0;
		flag = -1;
		fish.clear();
		q.push({ {start_x,start_y},0 });
		while (q.size()) BFS();
		if (fish.size() == 0) break;
		sort(fish.begin(), fish.end(), cmp);
		t += flag;
		cnt++;
		if (cnt == s) {
			cnt = 0;
			s++;
		}
		map[fish[0].second][fish[0].first] = 0;
		start_x = fish[0].first;
		start_y = fish[0].second;
	}
	cout << t;
	return 0;
}

void BFS() {
	pair<pair<int, int>, int> temp = q.front();
	q.pop();
	int x = temp.first.first;
	int y = temp.first.second;
	int d = temp.second;
	if (flag != -1 && d > flag) return;
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1) return;
	if (map[y][x] > s) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	if (map[y][x] != 0 && map[y][x] < s) {
		fish.push_back({ x,y });
		flag = d;
	}
	q.push({ {x + 1, y}, d + 1 });
	q.push({ {x - 1, y}, d + 1 });
	q.push({ {x, y + 1}, d + 1 });
	q.push({ {x, y - 1}, d + 1 });
	return;
}