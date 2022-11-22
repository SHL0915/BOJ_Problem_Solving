#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int N, M, G, R, ans, cnt;
vector <pair<int, int>> candidate;
int map[50][50];
int mark[50][50][2];
queue <pair<pair<int, int>, pair<int, int>>> q;
queue <pair<pair<int, int>, pair<int, int>>> temp;
set <pair<int, int>> blocked;

void BackTracking(int idx, string state);
void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) candidate.push_back({ j,i });
		}
	}
	BackTracking(0, "");
	cout << ans;
	return 0;
}

void BackTracking(int idx, string state) {
	if (idx == candidate.size()) {
		int rcnt = 0;
		int gcnt = 0;
		for (int i = 0; i < state.length(); i++) {
			if (state[i] == '1') rcnt++;
			else if (state[i] == '2') gcnt++;
		}
		if (rcnt != R || gcnt != G) return;
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				mark[i][j][0] = 0;
				mark[i][j][1] = 0;
			}
		}
		blocked.clear();
		for (int i = 0; i < state.length(); i++) {
			if (state[i] == '1') q.push({ {candidate[i].first, candidate[i].second},{1, 1} });
			else if (state[i] == '2') q.push({ {candidate[i].first, candidate[i].second},{1, 2} });
		}
		while (q.size()) {
			while (q.size()) BFS();
			while (temp.size()) {
				pair<pair<int, int>, pair<int, int>> f = temp.front();
				temp.pop();
				int x = f.first.first;
				int y = f.first.second;
				int d = f.second.first;
				int type = f.second.second;
				if (blocked.count({ x,y }) != 0) continue;
				q.push({ {x - 1,y},{d + 1,type} });
				q.push({ {x + 1,y},{d + 1,type} });
				q.push({ {x,y - 1},{d + 1,type} });
				q.push({ {x,y + 1},{d + 1,type} });
			}		
		}
		ans = max(ans, cnt);
		return;
	}
	else {
		BackTracking(idx + 1, state + '0');
		BackTracking(idx + 1, state + '1');
		BackTracking(idx + 1, state + '2');
	}
}

void BFS() {
	pair<pair<int, int>, pair<int, int>> f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second.first;
	int type = f.second.second;
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (map[y][x] == 0) return;
	if (blocked.count({ x,y }) != 0) return;
	if (mark[y][x][0] != 0) {
		if (d == mark[y][x][0] && type != mark[y][x][1]) {
			cnt++;
			blocked.insert({ x,y });
		}
		return;
	}
	mark[y][x][0] = d;
	mark[y][x][1] = type;
	temp.push({ {x,y},{d, type} });
}