#include <iostream>
#include <set>
#include <queue>
using namespace std;

int N, M, cnt1, cnt2, cnt3;
pair <int, int> A_Start, B_Start;
int map[1000][1000];
int mark[1000][1000][2];
queue <pair<pair<int, int>, pair<int,int>>> q;
queue <pair<pair<int, int>, pair<int, int>>> input;
set <pair<int, int>> three;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) q.push({ {j,i},{1,1} });
			else if (map[i][j] == 2) q.push({ {j,i},{1,2} });
		}
	}
	while (q.size()) {
		while (q.size()) BFS();
		while (input.size()) {
			pair<pair<int, int>, pair<int, int>> f = input.front();
			input.pop();
			int x = f.first.first;
			int y = f.first.second;
			int d = f.second.first;
			int type = f.second.second;
			if (three.count({ x,y }) != 0) continue;
			q.push({ {x - 1,y},{d + 1,type} });
			q.push({ {x + 1,y},{d + 1,type} });
			q.push({ {x,y - 1},{d + 1,type} });
			q.push({ {x,y + 1},{d + 1,type} });
		}
	}
	cout << cnt1 << " " << cnt2 << " " << cnt3;
	return 0;
}

void BFS() {
	pair<pair<int, int>, pair<int,int>> f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second.first;
	int type = f.second.second;
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (map[y][x] == -1) return;
	if (three.count({ x,y }) != 0) return;
	if (mark[y][x][0] != 0 && mark[y][x][1] != type && mark[y][x][0] == d) {
		if (mark[y][x][1] == 1) cnt1--;
		else cnt2--;
		cnt3++;
		three.insert({ x,y });
	}
	if (mark[y][x][0] != 0) return;
	mark[y][x][0] = d;
	mark[y][x][1] = type;
	if (type == 1) cnt1++;
	else cnt2++;
	input.push({ {x,y},{d,type} });
	return;
}