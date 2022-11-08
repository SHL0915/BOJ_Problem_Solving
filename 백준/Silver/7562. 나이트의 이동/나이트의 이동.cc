#include <iostream>
#include <queue>
using namespace std;

int T;
int l, x_start, y_start, x_end, y_end, ans;
int mark[300][300];
queue<pair<pair<int, int>, int>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> l;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) mark[i][j] = 0;
		}
		cin >> x_start >> y_start;
		cin >> x_end >> y_end;
		q.push({ {x_start,y_start},0 });
		while (q.size()) BFS();
		cout << ans << '\n';
	}
	return 0;
}

void BFS() {
	pair<pair<int, int>, int> temp = q.front();
	q.pop();
	int x = temp.first.first;
	int y = temp.first.second;
	int d = temp.second;
	if (x < 0 || x > l - 1 || y < 0 || y > l - 1) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	if (x == x_end && y == y_end) ans = d;
	q.push({ {x + 2,y + 1},d + 1 });
	q.push({ {x - 2,y + 1},d + 1 });
	q.push({ {x + 2,y - 1},d + 1 });
	q.push({ {x - 2,y - 1},d + 1 });
	q.push({ {x + 1,y + 2},d + 1 });
	q.push({ {x + 1,y - 2},d + 1 });
	q.push({ {x - 1,y + 2},d + 1 });
	q.push({ {x - 1,y - 2},d + 1 });
	return;
}