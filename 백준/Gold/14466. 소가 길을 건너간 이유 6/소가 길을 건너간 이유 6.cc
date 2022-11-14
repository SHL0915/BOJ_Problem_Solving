#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, K, R, ans;
int mark[101][101];
set <pair<pair<int, int>, pair<int,int>>> road;
vector <pair<int, int>> cow;

void clearMark();
void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K >> R;
	for (int i = 0; i < R; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		road.insert({ {b,a}, {d,c} });
		road.insert({ {d,c}, {b,a} });
	}
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> y >> x;
		cow.push_back({ x,y });
	}
	for (int i = 0; i < cow.size(); i++) {
		clearMark();
		DFS(cow[i].first, cow[i].second);
		for (int j = i + 1; j < cow.size(); j++) {
			if (mark[cow[j].second][cow[j].first] == 0) ans++;
		}
	}
	cout << ans;
	return 0;
}

void clearMark() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) mark[i][j] = 0;
	}
	return;
}

void DFS(int x, int y) {
	if (x < 1 || x > N || y < 1 || y > N) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	if (road.count({ {x,y},{x - 1,y} }) == 0) DFS(x - 1, y);
	if (road.count({ {x,y},{x,y - 1} }) == 0) DFS(x, y - 1);
	if (road.count({ {x,y},{x + 1,y} }) == 0) DFS(x + 1, y);
	if (road.count({ {x,y},{x,y + 1} }) == 0) DFS(x, y + 1);
	return;
}