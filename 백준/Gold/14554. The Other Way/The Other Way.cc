#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pli;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const long long mod = 1000000009;

struct cmp {
	bool operator() (pli A, pli B) {
		return A.first > B.first;
	}
};

int N, M, S, E;
vector <pli> graph[100001];
long long dist[100001];
vector <int> path[100001];
long long table[100001];

void Dijkstra(int start);
long long Find_PathNum(int vertex);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> S >> E;
	for (int i = 0; i < M; i++) {
		int A, B;
		long long C;
		cin >> A >> B >> C;
		graph[A].push_back({ C,B });
		graph[B].push_back({ C,A });
	}
	Dijkstra(S);
	table[S] = 1;
	cout << Find_PathNum(E);
	return 0;
}

void Dijkstra(int start) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	priority_queue <pli, vector<pli>, cmp> pq;
	pq.push({ 0, start });
	dist[start] = 0;
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

long long Find_PathNum(int vertex) {
	if (table[vertex] != 0) return table[vertex];
	for (int i = 0; i < path[vertex].size(); i++) table[vertex] = (table[vertex] + Find_PathNum(path[vertex][i])) % mod;
	return table[vertex];
}