#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int W, H, k;
int map[100][100];
int mark[100][100];
pair <int, int> arr[2];
queue <pair<pair<int, int>, pair<int,int>>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < W; j++) {
			if (input[j] == '*') map[i][j] = 1;
			else if (input[j] == 'C') arr[k++] = { j,i };
		}
	}
	mark[arr[0].second][arr[0].first] = 1;
	q.push({ {arr[0].first - 1,arr[0].second},{1, 0} });
	q.push({ {arr[0].first + 1,arr[0].second},{1, 1} });
	q.push({ {arr[0].first,arr[0].second - 1},{1, 2} });
	q.push({ {arr[0].first,arr[0].second + 1},{1, 3} });
	while (q.size()) BFS();
	cout << mark[arr[1].second][arr[1].first] - 1;
	return 0;
}

void BFS() {
	pair<pair<int, int>, pair<int, int>> f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int cnt = f.second.first;
	int d = f.second.second;
	if (x < 0 || x > W - 1 || y < 0 || y > H - 1) return;
	if (map[y][x] == 1) return;
	if (mark[y][x] != 0 && mark[y][x] < cnt) return;
	mark[y][x] = cnt;
	if (d == 0) {
		q.push({ {x - 1, y},{cnt, 0} });
		q.push({ {x, y - 1},{cnt + 1, 2} });
		q.push({ {x, y + 1},{cnt + 1, 3} });
	}
	else if (d == 1) {
		q.push({ {x + 1, y},{cnt, 1} });
		q.push({ {x, y - 1},{cnt + 1, 2} });
		q.push({ {x, y + 1},{cnt + 1, 3} });
	}
	else if (d == 2) {
		q.push({ {x - 1, y},{cnt + 1, 0} });
		q.push({ {x + 1, y},{cnt + 1, 1} });
		q.push({ {x, y - 1},{cnt, 2} });
	}
	else {
		q.push({ {x - 1, y},{cnt + 1, 0} });
		q.push({ {x + 1, y},{cnt + 1, 1} });
		q.push({ {x, y + 1},{cnt , 3} });
	}
}