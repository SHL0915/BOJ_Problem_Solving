#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const long long INF = 1000000000;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int W, H;
int arr[25][25];
long long mark[25][25];
long long dist[25][25];
long long table[(1 << 15)][15];

pii s;
vector <pii> pos;
queue <pair<pii, int>> q;

void clearMark();
void BFS();
long long DP(int state, int now);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> W >> H;
		if (W == 0 && H == 0) break;
		pos.clear();
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 25; j++) {
				dist[i][j] = 0;
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < H; i++) {
			string S;
			cin >> S;
			for (int j = 0; j < W; j++) {
				if (S[j] == '*') pos.push_back({ j,i });
				else if (S[j] == 'o') s = { j,i };
				else if (S[j] == 'x') arr[i][j] = 1;
			}
		}
		for (int i = 0; i < pos.size(); i++) {
			clearMark();
			q.push({ {pos[i].first, pos[i].second},1 });
			while (q.size()) BFS();
			dist[0][i + 1] = (mark[s.second][s.first] == 0 ? INF : mark[s.second][s.first] - 1);
			dist[i + 1][0] = (mark[s.second][s.first] == 0 ? INF : mark[s.second][s.first] - 1);
			for (int j = i + 1; j < pos.size(); j++) {
				dist[i + 1][j + 1] = (mark[pos[j].second][pos[j].first] == 0 ? INF : mark[pos[j].second][pos[j].first] - 1);
				dist[j + 1][i + 1] = (mark[pos[j].second][pos[j].first] == 0 ? INF : mark[pos[j].second][pos[j].first] - 1);
			}
		}		
		memset(table, -1, sizeof(table));
		long long ans = DP(1, 0);
		if (ans == INF) cout << -1 << '\n';
		else cout << ans << '\n';
	}
	return 0;
}

void clearMark() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) mark[i][j] = 0;
	}
}

void BFS() {
	pair<pii, int> f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second;
	if (x < 0 || x > W - 1 || y < 0 || y > H - 1) return;
	if (arr[y][x] == 1) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = d;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		q.push({ {nx,ny},d + 1 });
	}
}

long long DP(int state, int now) {
	if (state == (1 << (pos.size() + 1)) - 1) return 0;
	if (table[state][now] != -1) return table[state][now];
	table[state][now] = INF;
	for (int i = 0; i <= pos.size(); i++) {
		if (state & (1 << i)) continue;
		table[state][now] = min(table[state][now], DP(state ^ (1 << i), i) + dist[now][i]);
	}
	return table[state][now];
}