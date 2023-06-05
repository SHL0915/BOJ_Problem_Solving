#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

struct node {
	int x, y, d;
};

int N;
int arr[25][25];
int mark[25][25][4][25][25][4];
queue <pair<node, node>> q;

void BFS();
void go(node& a);
void left(node& a);
void right(node& a);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'E') arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}

	memset(mark, -1, sizeof(mark));

	q.push({ {0, N - 1, 0}, {0, N - 1, 1} });
	mark[N - 1][0][0][N - 1][0][1] = 0;

	while (q.size()) BFS();

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void BFS() {
	pair <node, node> f = q.front(); q.pop();
	node a = f.first, b = f.second;
	int now = mark[a.y][a.x][a.d][b.y][b.x][b.d];

	if (a.x == N - 1 && a.y == 0 && b.x == N - 1 && b.y == 0) {
		cout << now;
		exit(0);
	}

	node nA = a, nB = b;
	go(nA); go(nB);

	if (mark[nA.y][nA.x][nA.d][nB.y][nB.x][nB.d] == -1) {
		mark[nA.y][nA.x][nA.d][nB.y][nB.x][nB.d] = now + 1;
		q.push({ nA,nB });
	}

	nA = a, nB = b;
	left(nA); left(nB);

	if (mark[nA.y][nA.x][nA.d][nB.y][nB.x][nB.d] == -1) {
		mark[nA.y][nA.x][nA.d][nB.y][nB.x][nB.d] = now + 1;
		q.push({ nA,nB });
	}

	nA = a, nB = b;
	right(nA); right(nB);

	if (mark[nA.y][nA.x][nA.d][nB.y][nB.x][nB.d] == -1) {
		mark[nA.y][nA.x][nA.d][nB.y][nB.x][nB.d] = now + 1;
		q.push({ nA,nB });
	}

	return;
}

void go(node& a) {
	int nx = a.x + dx[a.d];
	int ny = a.y + dy[a.d];

	if (a.x == N - 1 && a.y == 0) return;

	if (nx >= N || nx < 0 || ny >= N || ny < 0 || arr[ny][nx] == 1) return;
	else {
		a.x = nx;
		a.y = ny;
	}
	return;
}

void left(node& a) {
	a.d += 3; a.d %= 4;
	return;
}

void right(node& a) {
	a.d++; a.d %= 4;
	return;
}