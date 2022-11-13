#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, ans = 1234567890, house, cnt;
int map[51][51];
int mark[51][51];
set <pair<int, int>> s;
pair<int, int> S;
vector <int> height;

void DFS(int x, int y, int min_h, int max_h);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < N; j++) {
			if (input[j] == 'P') S = { j,i };
			else if (input[j] == 'K') {
				s.insert({ j,i });
				house++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			height.push_back(map[i][j]);
		}
	}
	sort(height.begin(), height.end());
	height.erase(unique(height.begin(), height.end()), height.end());
	int lpos = 0, rpos = 0;
	while (lpos < height.size() && rpos < height.size()) {
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) mark[i][j] = 0;
		}
		DFS(S.first, S.second, height[lpos], height[rpos]);
		if (cnt == house) {
			ans = min(ans, height[rpos] - height[lpos]);
			lpos++;
		}
		else rpos++;
	}
	cout << ans;
	return 0;
}

void DFS(int x, int y, int min_h, int max_h) {
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1) return;
	if (map[y][x] > max_h || map[y][x] < min_h) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	if (s.count({ x,y }) != 0) cnt++;
	DFS(x - 1, y, min_h, max_h);
	DFS(x + 1, y, min_h, max_h);
	DFS(x, y - 1, min_h, max_h);
	DFS(x, y + 1, min_h, max_h);
	DFS(x - 1, y - 1, min_h, max_h);
	DFS(x - 1, y + 1, min_h, max_h);
	DFS(x + 1, y - 1, min_h, max_h);
	DFS(x + 1, y + 1, min_h, max_h);
	return;
}