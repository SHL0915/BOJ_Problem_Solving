#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

struct cmp {
	bool operator() (pair<int, pair<int, int>> A, pair<int, pair<int, int>> B) {
		return A.first > B.first;
	}
};

int N;
int arr[50][50];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int dist[50][50];

void Dijkstra(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i][j] = s[j] - '0';
			arr[i][j] ^= 1;
		}
	}
	Dijkstra(0, 0);
	cout << dist[N - 1][N - 1];
	return 0;
}

void Dijkstra(int x, int y) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) dist[i][j] = INF;
	}
	priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
	dist[y][x] = 0;
	pq.push({ 0, {x,y} });
	while (pq.size()) {
		int now_x = pq.top().second.first;
		int now_y = pq.top().second.second;
		int val = pq.top().first;
		pq.pop();
		if (dist[now_y][now_x] < val) continue;
		for (int i = 0; i < 4; i++) {
			int nx = now_x + dx[i];
			int ny = now_y + dy[i];
			if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) continue;
			int new_val = val + arr[ny][nx];
			if (dist[ny][nx] > new_val) {
				dist[ny][nx] = new_val;
				pq.push({ new_val, {nx,ny} });
			}
		}
	}
}