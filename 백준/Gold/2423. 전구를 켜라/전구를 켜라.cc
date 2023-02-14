#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1234567890;

struct cmp {
	bool operator() (pair<int, pair<int, int>> A, pair<int, pair<int, int>> B) {
		return A.first > B.first;
	}
};

int N, M;
vector <pair<pair<int, int>, int>> graph[505][505];
int dist[505][505];

void Dijkstra(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '/') {
				graph[i][j + 1].push_back({ {j, i + 1}, 0 });
				graph[i + 1][j].push_back({ {j + 1, i}, 0 });
				graph[i][j].push_back({ {j + 1,i + 1}, 1 });
				graph[i + 1][j + 1].push_back({ {j,i}, 1 });
			}
			else {
				graph[i][j + 1].push_back({ {j, i + 1}, 1 });
				graph[i + 1][j].push_back({ {j + 1, i}, 1 });
				graph[i][j].push_back({ {j + 1,i + 1}, 0 });
				graph[i + 1][j + 1].push_back({ {j,i}, 0 });
			}
		}
	}
	Dijkstra(0, 0);
	if (dist[N][M] == INF) cout << "NO SOLUTION";
	else cout << dist[N][M];
	return 0;
}

void Dijkstra(int x, int y) {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) dist[i][j] = INF;
	}
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
	pq.push({ 0,{x,y} });
	dist[y][x] = 0;
	while (pq.size()) {
		pair<int, pair<int, int>> t = pq.top();
		pq.pop();
		int now_x = t.second.first;
		int now_y = t.second.second;
		int now_val = t.first;
		if (dist[now_y][now_x] < now_val) continue;
		for (int i = 0; i < graph[now_y][now_x].size(); i++) {
			int new_x = graph[now_y][now_x][i].first.first;
			int new_y = graph[now_y][now_x][i].first.second;
			int new_val = dist[now_y][now_x] + graph[now_y][now_x][i].second;
			if (dist[new_y][new_x] > new_val) {
				dist[new_y][new_x] = new_val;
				pq.push({ new_val, {new_x,new_y} });
			}
		}
	}	
}