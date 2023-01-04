#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M, P, flag;
int mv[10];
int arr[1005][1005];
int mark[1005][1005];
int ans[10];
queue <pair<pii, int>> q[10], cand[10];

void color(int type);
void BFS(int type);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> P;
	for (int i = 1; i <= P; i++) cin >> mv[i];
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) {
			if (s[j - 1] == '.') arr[i][j] = 0;
			else if (s[j - 1] == '#') arr[i][j] = -1;
			else arr[i][j] = s[j - 1] - '0';
		}
	}
	memset(mark, INF, sizeof(mark));
	while (1) {
		flag = 0;
		for (int i = 1; i <= P; i++) color(i);
		if (flag == 0) break;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] > 0) ans[arr[i][j]]++;
		}
	}
	for (int i = 1; i <= P; i++) cout << ans[i] << " ";
	return 0;
}

void color(int type) {
	if (q[type].size() == 0) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) if (arr[i][j] == type) q[type].push({{j,i},0});
		}
	}	
	while (q[type].size()) BFS(type);
	while (cand[type].size()) {
		q[type].push(cand[type].front());
		cand[type].pop();
	}
	return;
}

void BFS(int type) {
	pair<pii, int> f = q[type].front();
	q[type].pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second;
	if (d > mv[type]) return;
	if (x < 1 || x > M || y < 1 || y > N) return;
	if (arr[y][x] != 0 && arr[y][x] != type) return;
	if (mark[y][x] <= d) return;
	mark[y][x] = d;
	if (arr[y][x] == 0) {
		arr[y][x] = type;
		cand[type].push({ {x,y},0 });
		flag = 1;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		q[type].push({ {nx,ny},d + 1 });
	}
	return;
}