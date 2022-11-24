#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pli;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct cmp {
	bool operator() (pli A, pli B) {
		return A.first > B.first;
	}
};

int N, M, S, E;
vector <pli> graph[1001];
long long dist[1001];
vector <int> path[1001];
deque <int> ans;

void Dijkstra(int start);
void Find_Path(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		long long C;
		cin >> A >> B >> C;
		graph[A].push_back({ C,B });
	}
	cin >> S >> E;
	Dijkstra(S);
	Find_Path(E);
	cout << dist[E] << '\n';
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	return 0;
}

void Dijkstra(int start) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	priority_queue <pli, vector<pli>, cmp> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (pq.size()) {
		int now = pq.top().second;
		long long val = pq.top().first;
		pq.pop();
		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].second;
			long long new_val = val + graph[now][i].first;
			if (dist[next] > new_val) {
				dist[next] = new_val;
				path[next].clear();
				path[next].push_back(now);
				pq.push({ new_val, next });
			}
			else if (dist[next] == new_val) path[next].push_back(now);
		}
	}
}

void Find_Path(int node) {
	ans.push_front(node);
	if (node == S) return;
	Find_Path(path[node][0]);
	return;
}