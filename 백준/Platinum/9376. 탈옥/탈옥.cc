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

int t, H, W, cnt, ans;
int arr[105][105];
int A[105][105];
int B[105][105];
int C[105][105];
pair<int, int> pos[2];
int dist[105][105];

void Dijkstra(int start_x, int start_y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> H >> W;
		cnt = 0;
		ans = INF;
		memset(arr, 0, sizeof(arr));
		for (int i = 1; i <= H; i++) {
			string s;
			cin >> s;
			for (int j = 1; j <= W; j++) {
				if (s[j - 1] == '*') arr[i][j] = INF;
				else if (s[j - 1] == '#') arr[i][j] = 1;
				else arr[i][j] = 0;
				if (s[j - 1] == '$') pos[cnt++] = { j,i };
			}
		}
		Dijkstra(0, 0);
		for (int i = 0; i <= H + 1; i++) {
			for (int j = 0; j <= W + 1; j++) A[i][j] = dist[i][j];
		}
		Dijkstra(pos[0].first, pos[0].second);
		for (int i = 0; i <= H + 1; i++) {
			for (int j = 0; j <= W + 1; j++) B[i][j] = dist[i][j];
		}
		Dijkstra(pos[1].first, pos[1].second);
		for (int i = 0; i <= H + 1; i++) {
			for (int j = 0; j <= W + 1; j++) C[i][j] = dist[i][j];
		}
		for (int i = 0; i <= H + 1; i++) {
			for (int j = 0; j <= W + 1; j++) {
				if (arr[i][j] != INF) {
					if (A[i][j] == INF || B[i][j] == INF || C[i][j] == INF) continue;
					if (arr[i][j] == 1) ans = min(ans, A[i][j] + B[i][j] + C[i][j] - 2);
					else ans = min(ans, A[i][j] + B[i][j] + C[i][j]);
				}
			}
		}		
		cout << ans << '\n';
	}
	return 0;
}

void Dijkstra(int start_x, int start_y) {
	memset(dist, INF, sizeof(dist));
	priority_queue <piii, vector<piii>, cmp> pq;
	pq.push({ arr[start_y][start_x], {start_x, start_y} });
	dist[start_y][start_x] = arr[start_y][start_x];
	while (pq.size()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int val = pq.top().first;
		pq.pop();
		if (dist[y][x] < val) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx > W + 1 || ny < 0 || ny > H + 1) continue;
			if (arr[ny][nx] == INF) continue;
			int new_val = val + arr[ny][nx];
			if (dist[ny][nx] > new_val) {
				dist[ny][nx] = new_val;
				pq.push({ new_val, { nx,ny } });
			}
		}
	}
}