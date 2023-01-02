#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> piii;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1 };

int N, M, H, W;
pair <int, int> S, F;

int arr[1001][1001];
int psum[1001][1001];
int mark[1001][1001];
queue <piii> q;

void BFS();
int sum(pair<int, int> p);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			psum[i][j] = psum[i - 1][j] + psum[i][j - 1] + arr[i][j] - psum[i - 1][j - 1];
		}
	}
	cin >> H >> W >> S.second >> S.first >> F.second >> F.first;
	memset(mark, -1, sizeof(mark));
	q.push({ S,0 });
	while (q.size()) BFS();
	cout << mark[F.second][F.first];
	return 0;
}

void BFS() {
	piii f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second;
	if (x < 1 || x > M - W + 1 || y < 1 || y > N - H + 1) return;
	if (sum({ x,y }) != 0) return;
	if (mark[y][x] != -1) return;
	mark[y][x] = d;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		q.push({ {nx,ny},d + 1 });
	}
}

int sum(pair<int, int> p) {
	int x = p.first;
	int y = p.second;
	return psum[y + H - 1][x + W - 1] - psum[y + H - 1][x - 1] - psum[y - 1][x + W - 1] + psum[y - 1][x - 1];
}