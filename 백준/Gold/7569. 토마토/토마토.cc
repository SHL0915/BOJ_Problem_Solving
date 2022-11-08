#include <iostream>
#include <queue>
using namespace std;

int M, N, H, ans;
int tomato[100][100][100];
int mark[100][100][100];
queue <pair<pair<pair<int, int>, int>, int>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) q.push({ {{k,j},i},0 });
				if (tomato[i][j][k] == -1) mark[i][j][k] = 0;
				else mark[i][j][k] = -1;
			}
		}
	}
	while (q.size()) BFS();
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (mark[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(ans, mark[i][j][k]);
			}
		}
	}
	cout << ans;
	return 0;
}

void BFS() {
	pair<pair<pair<int, int>, int>, int> temp = q.front();
	q.pop();
	int x = temp.first.first.first;
	int y = temp.first.first.second;
	int z = temp.first.second;
	int d = temp.second;
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1 || z < 0 || z > H - 1) return;
	if (mark[z][y][x] != -1) return;
	mark[z][y][x] = d;
	q.push({ {{x + 1,y},z},d + 1 });
	q.push({ {{x - 1,y},z},d + 1 });
	q.push({ {{x,y + 1},z},d + 1 });
	q.push({ {{x,y - 1},z},d + 1 });
	q.push({ {{x,y},z + 1},d + 1 });
	q.push({ {{x,y},z - 1},d + 1 });
	return;
}