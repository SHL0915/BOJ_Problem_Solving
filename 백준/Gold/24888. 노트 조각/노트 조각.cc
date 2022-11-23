#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000;

struct cmp {
	bool operator() (pair<ll, int> A, pair<ll, int> B){
		return A.first > B.first;
	}
};

int N, M, cnt;
vector <pair<int, ll>> graph[200001];
int paper[200001];
ll dist[200001][2];
vector <int> path[200001];
deque <int> ans;

void Dijkstra(int start);
void FindPath(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
	for (int i = 1; i <= N; i++) {
		cin >> paper[i];
		if (paper[i] == 1) cnt++;
	}
	Dijkstra(1);
	if (dist[N][1] < cnt) {
		cout << -1;
		return 0;
	}
	FindPath(N);
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	return 0;
}

void Dijkstra(int start) {
	for (int i = 1; i <= N; i++) dist[i][0] = INF;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, cmp> pq;
	pq.push({ 0, start });
	if (paper[start] == 1) dist[start][1] = 1;
	dist[start][0] = 0;
	while (pq.size()) {
		int now = pq.top().second;
		ll val = pq.top().first;
		pq.pop();
		if (dist[now][0] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			ll next_val = val + graph[now][i].second;
			if (dist[next][0] > next_val) {
				path[next].clear();
				path[next].push_back(now);
				dist[next][0] = next_val;
				dist[next][1] = dist[now][1] + paper[next];
				pq.push({ next_val, next });
			}
			else if (dist[next][0] == next_val) {
				dist[next][1] = max(dist[next][1], dist[now][1] + paper[next]);
				path[next].push_back(now);
			}
		}
	}
}

void FindPath(int node) {
	ans.push_front(node);
	if (node == 1) return;	
	else {
		ll max_num = 0;
		for (int i = 0; i < path[node].size(); i++) max_num = max(max_num, dist[path[node][i]][1]);
		for (int i = 0; i < path[node].size(); i++) {
			if (dist[path[node][i]][1] == max_num) {
				FindPath(path[node][i]);
				break;
			}
		}
	}
}