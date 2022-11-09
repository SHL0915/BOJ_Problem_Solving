#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1000000000LL;

struct cmp {
	bool operator() (pair<pair<long long, long long>, long long> A, pair<pair<long long, long long>, long long> B) {
		if (A.first.first == B.first.first) return A.first.second > A.first.second;
		return A.first.first > B.first.first;
	}
};

int T;
int N, M, K;
vector <pair<int, pair<int, int>>> graph[101];
long long dist[10001][101];
long long ans;

void Dijkstra();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans = INF;
		cin >> N >> M >> K;
		for (int i = 1; i <= N; i++) graph[i].clear();
		for (int i = 0; i < K; i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			graph[u].push_back({ v,{c,d} });
		}
		Dijkstra();
		for (int i = 0; i <= M; i++) ans = min(ans, dist[i][N]);		
		if (ans == INF) cout << "Poor KCM\n";
		else cout << ans << '\n';
	}
	return 0;
}

void Dijkstra() {
	for (int i = 0; i <= M; i++) {
		for (int j = 2; j <= N; j++) dist[i][j] = INF;
	}
	priority_queue < pair<pair<long long, long long>, long long>, vector<pair<pair<long long, long long>, long long>>, cmp> pq;
	pq.push({ {0,0},1 });
	while (pq.size()) {
		long long idx = pq.top().second;
		long long cost = pq.top().first.second;
		long long t = pq.top().first.first;
		pq.pop();		
		if (dist[cost][idx] < t) continue;
		for (int i = 0; i < graph[idx].size(); i++) {
			long long next = graph[idx][i].first;
			long long next_cost = cost + graph[idx][i].second.first;
			long long next_time = t + graph[idx][i].second.second;
			if (next_cost > M) continue;
			if (dist[next_cost][next] > next_time) {
				for (int j = next_cost; j <= M; j++) {
					if (dist[j][next] <= next_time) break;
					dist[j][next] = next_time;
				}
				pq.push({ {next_time, next_cost}, next });
			}
		}
	}
}