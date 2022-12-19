#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;
const int INF = 0x3f3f3f3f;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct cmp {
	bool operator() (piii A, piii B) {
		return A.first > B.first;
	}
};

int N, TC;
int arr[125][125];
int dist[125][125];

void Dijkstra(int start_x, int start_y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> N;
		if (N == 0) break;
		TC++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cin >> arr[i][j];
		}
		Dijkstra(0, 0);
		cout << "Problem " << TC << ": " << dist[N - 1][N - 1] << '\n';
	}
	return 0;
}

void Dijkstra(int start_x, int start_y) {
	memset(dist, INF, sizeof(dist));
	priority_queue <piii, vector<piii>, cmp> pq;
	pq.push({ arr[start_x][start_y], {start_x, start_y} });
	dist[start_x][start_y] = arr[start_x][start_y];
	while (pq.size()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int val = pq.top().first;
		pq.pop();
		if (dist[y][x] < val) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) continue;
			int new_val = val + arr[ny][nx];
			if (dist[ny][nx] > new_val) {
				dist[ny][nx] = new_val;
				pq.push({ new_val, {nx,ny} });
			}
		}
	}
}