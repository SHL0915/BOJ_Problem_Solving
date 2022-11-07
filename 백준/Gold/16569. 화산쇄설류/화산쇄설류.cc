#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 100000000LL;

int M, N, V, X, Y, ptr;
int map[101][101];
int mark1[101][101];
int mark2[101][101]; // time
pair<int, pair<int, int>> volcano[5000];
pair<int, int> max_pair;
queue<pair<pair<int, int>, int>> q; // {{{x,y},d}}

void BFS1();
void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N >> V;
	cin >> X >> Y;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			mark2[i][j] = INF;
		}
	}	
	for (int i = 0; i < V; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		volcano[i] = { t, {x,y} };
		mark1[x][y] = 1;
	}
	for (int i = 0; i < V; i++) q.push({ { volcano[i].second.first, volcano[i].second.second }, volcano[i].first });
	while (q.size()) BFS1();
	q.push({ {X,Y},0 });
	while (q.size()) BFS();	
	cout << max_pair.first << " " << max_pair.second;
	return 0;
}

void BFS1() {
	pair<pair<int, int>, int> temp = q.front();
	int x = temp.first.first;
	int y = temp.first.second;
	int d = temp.second;
	q.pop();
	if (x < 1 || y < 1 || x > M || y > N) return;
	if (mark2[x][y] <= temp.second) return;
	mark2[x][y] = temp.second;	
	q.push({ {x - 1, y},d + 1 });
	q.push({ {x + 1, y},d + 1 });
	q.push({ {x, y - 1},d + 1 });
	q.push({ {x, y + 1},d + 1 });
	return;
}

void BFS() {
	pair<pair<int, int>, int> temp = q.front();
	int x = temp.first.first;
	int y = temp.first.second;
	int d = temp.second;
	q.pop();
	if (x < 1 || y < 1 || x > M || y > N) return;
	if (mark1[x][y] != 0) return;
	mark1[x][y] = 1;
	if (temp.second < mark2[x][y] && max_pair.first < map[x][y]) {
		max_pair = { map[x][y],d };
	}
	q.push({ {x - 1, y},d + 1 });
	q.push({ {x + 1, y},d + 1 });
	q.push({ {x, y - 1},d + 1 });
	q.push({ {x, y + 1},d + 1 });
	return;
}