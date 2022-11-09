#include <iostream>
#include <queue>
using namespace std;

const int INF = 1000000000;

struct cmp {
	bool operator() (pair<int, pair<int, int>> A, pair<int, pair<int, int>> B) {
		return A.first > B.first;
	}
};

int N, cnt, area, ans = INF;
char org[1000][1000];
int colored_map[1000][1000];
int mark[1000][1000];
int dist[1000][1000];

void DFS(int x, int y, char c);
void color(int x, int y, int a, char c);
void Dijkstra();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < N; j++) org[i][j] = input[j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i == 0 && j == 0) || (i == N - 1 && j == N - 1)) continue;
			else if (mark[i][j] == 0) {
				area++;
				cnt = 0;
				DFS(j, i, org[i][j]);
				color(j, i, cnt, org[i][j]);
			}
		}
	}	
	Dijkstra();	
	for (int i = 1; i < N; i++) ans = min(ans, dist[i][0]);
	for (int i = 1; i < N; i++) ans = min(ans, dist[N - 1][i]);
	cout << ans;
	return 0;
}

void DFS(int x, int y, char c) {
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1) return;
	if (org[y][x] != c) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = area;
	cnt++;
	DFS(x + 1, y, c);
	DFS(x - 1, y, c);
	DFS(x, y + 1, c);
	DFS(x, y - 1, c);
	return;
}

void color(int x, int y, int a, char c) {
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1) return;
	if (org[y][x] != c) return;
	if (colored_map[y][x] != 0) return;
	colored_map[y][x] = a;
	color(x + 1, y, a, c);
	color(x - 1, y, a, c);
	color(x, y + 1, a, c);
	color(x, y - 1, a, c);
	return;
}

void Dijkstra() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) dist[i][j] = INF;
	}
	priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
	for (int i = 1; i < N; i++) {
		dist[0][i] = colored_map[0][i];
		pq.push({ dist[0][i],{i,0} });
	}	
	for (int i = 0; i < N - 1; i++) {
		dist[i][N - 1] = colored_map[i][N - 1];
		pq.push({ dist[i][N - 1],{N - 1,i} });
	}
	while (pq.size()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();
		if (dist[y][x] < cost) continue;
		if (x > 0 && !(x == 1 && y == 0)) {
			int next_cost = cost;
			if (mark[y][x] != mark[y][x - 1]) next_cost += colored_map[y][x - 1];
			if (dist[y][x - 1] > next_cost) {
				dist[y][x - 1] = next_cost;
				pq.push({ next_cost , {x - 1, y} });
			}
		}
		if (x < N - 1 && !(x == N - 2 && y == N - 1)) {
			int next_cost = cost;
			if (mark[y][x] != mark[y][x + 1]) next_cost += colored_map[y][x + 1];
			if (dist[y][x + 1] > next_cost) {
				dist[y][x + 1] = next_cost;
				pq.push({ next_cost , {x + 1, y} });
			}
		}
		if (y > 0 && !(x == 0 && y == 1)) {
			int next_cost = cost;
			if (mark[y][x] != mark[y - 1][x]) next_cost += colored_map[y - 1][x];
			if (dist[y - 1][x] > next_cost) {
				dist[y - 1][x] = next_cost;
				pq.push({ next_cost , {x, y - 1} });
			}
		}
		if (y < N - 1 && !(x == N - 1 && y == N - 2)) {
			int next_cost = cost;
			if (mark[y][x] != mark[y + 1][x]) next_cost += colored_map[y + 1][x];
			if (dist[y + 1][x] > next_cost) {
				dist[y + 1][x] = next_cost;
				pq.push({ next_cost , {x, y + 1} });
			}
		}
		if (x > 0 && y > 0 && !(x == 1 && y == 1)) {
			int next_cost = cost;
			if (mark[y][x] != mark[y - 1][x - 1]) next_cost += colored_map[y - 1][x - 1];
			if (dist[y - 1][x - 1] > next_cost) {
				dist[y - 1][x - 1] = next_cost;
				pq.push({ next_cost , {x - 1, y - 1} });
			}
		}
		if (x < N - 1 && y > 0) {
			int next_cost = cost;
			if (mark[y][x] != mark[y - 1][x + 1]) next_cost += colored_map[y - 1][x + 1];
			if (dist[y - 1][x + 1] > next_cost) {
				dist[y - 1][x + 1] = next_cost;
				pq.push({ next_cost , {x + 1, y - 1} });
			}
		}
		if (x > 0 && y < N - 1) {
			int next_cost = cost;
			if (mark[y][x] != mark[y + 1][x - 1]) next_cost += colored_map[y + 1][x - 1];
			if (dist[y + 1][x - 1] > next_cost) {
				dist[y + 1][x - 1] = next_cost;
				pq.push({ next_cost , {x - 1, y + 1} });
			}
		}
		if (x < N - 1 && y < N - 1 && !(x == N - 2 && y == N - 2)) {
			int next_cost = cost;
			if (mark[y][x] != mark[y + 1][x + 1]) next_cost += colored_map[y + 1][x + 1];
			if (dist[y + 1][x + 1] > next_cost) {
				dist[y + 1][x + 1] = next_cost;
				pq.push({ next_cost , {x + 1, y + 1} });
			}
		}
	}
}