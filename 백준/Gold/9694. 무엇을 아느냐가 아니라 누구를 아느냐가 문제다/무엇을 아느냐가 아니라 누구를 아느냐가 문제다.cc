#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1234567890;

struct cmp {
	bool operator() (pair<int, int> A, pair<int, int> B) {
		return A.first > B.first;
	}
};

int T, N, M, cnt;
vector <pair<int, int>> graph[20];
vector <int> path;
int dist[20][2];

void Dijkstra(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cnt++;
		cin >> N >> M;
		path.clear();
		for (int i = 0; i < M; i++) graph[i].clear();
		for (int i = 0; i < N; i++) {
			int A, B, C;
			cin >> A >> B >> C;
			graph[A].push_back({ B,C });
			graph[B].push_back({ A,C });
		}
		Dijkstra(0);
		cout << "Case #" << cnt << ":";
		if (dist[M - 1][0] == INF) cout << " " << -1 << '\n';
		else {
			int temp = M - 1;
			while (1) {
				if (temp == -1) break;
				path.push_back(temp);
				temp = dist[temp][1];
			}
			for (int i = path.size() - 1; i >= 0; i--) cout << " " << path[i];
			cout << '\n';
		}
	}
	return 0;
}

void Dijkstra(int start) {
	for (int i = 0; i < M; i++) dist[i][0] = INF;
	priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ 0, start });
	dist[start][0] = 0;
	dist[start][1] = -1;
	while (pq.size()) {
		pair<int, int> t = pq.top();
		pq.pop();
		int now = t.second;
		int val = t.first;
		if (dist[now][0] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int next_val = val + graph[now][i].second;
			if (dist[next][0] > next_val) {
				dist[next][0] = next_val;
				dist[next][1] = now;
				pq.push({ next_val, next });					
			}
		}
	}
}