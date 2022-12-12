#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> piii;
const int INF = 0x3f3f3f3f;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M, ans = INF;
int arr[50][50];
int mark[50][50];
int bt[10];
vector <pair<int, int>> candidate;
queue <piii> q;

void BackTracking(int k, int start);
void init();
void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				candidate.push_back({ j,i });
				arr[i][j] = 0;
			}
			else if (arr[i][j] == 1) arr[i][j] = -1;
		}
	}
	BackTracking(0, 0);
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

void BackTracking(int k, int start) {
	if (k == M) {
		int temp = -1;
		init();
		for (int i = 0; i < M; i++) {
			int x = candidate[bt[i]].first;
			int y = candidate[bt[i]].second;
			q.push({ {x,y}, 1 });
		}
		while (q.size()) BFS();
		for (int i = 0; i < candidate.size(); i++) {
			int x = candidate[i].first;
			int y = candidate[i].second;
			mark[y][x] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp = max(temp, mark[i][j]);
				if (mark[i][j] == 0) return;
			}
		}
		ans = min(ans, temp - 1);
	}
	else {
		for (int i = start; i < candidate.size(); i++) {
			bt[k] = i;
			BackTracking(k + 1, i + 1);
		}
	}
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) mark[i][j] = arr[i][j];
	}
}

void BFS() {
	piii f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second;
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = d;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		q.push({ {nx,ny}, d + 1 });
	}
}