#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M, cnt, ans = INF;
int arr[51][51];
pii S, C[2];
int mark[51][51][4][4];
queue <pair<pii, pair<pii, int>>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '#') arr[i][j] = 1;
			else if (s[j] == 'S') S = { j,i };
			else if (s[j] == 'C') C[cnt++] = { j,i };
		}
	}
	for (int i = 0; i < 4; i++) q.push({ S, {{0, i}, 0} });
	memset(mark, -1, sizeof(mark));
	while (q.size()) BFS();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				if (mark[i][j][3][k] != -1) ans = min(ans, mark[i][j][3][k]);
			}
		}
	}
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

void BFS() {
	pair<pii, pair<pii, int>> f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int visited = f.second.first.first;
	int dir = f.second.first.second;
	int d = f.second.second;
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (arr[y][x] == 1) return;
	if (x == C[0].first && y == C[0].second) visited |= 1;
	if (x == C[1].first && y == C[1].second) visited |= 2;
	if (mark[y][x][visited][dir] != -1) return;
	mark[y][x][visited][dir] = d;	
	for (int i = 0; i < 4; i++) {
		if (i == dir) continue;
		int nx = x + dx[i];
		int ny = y + dy[i];
		q.push({ {nx,ny},{{visited, i}, d + 1} });
	}
}