#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 100000000000;

struct cmp {
	bool operator() (pair<long long, long long> A, pair<long long, long long> B){
		return A.second > B.second;
	}
};

long long T, n, m, t, s, g, h, a, b, d, x;
vector <pair<long long, long long>> graph[2001];
vector <long long> candidate;
long long dist[2001];
long long V;

void Dijkstra(long long start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m >> t >> s >> g >> h;
		for (int i = 1; i <= n; i++) graph[i].clear();
		candidate.clear();
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			if ((a == g && b == h) || (a == h && b == g)) V = d;
			graph[a].push_back({ b,d });
			graph[b].push_back({ a,d });
		}
		for (int i = 0; i < t; i++) {
			cin >> x;
			candidate.push_back(x);
		}
		sort(candidate.begin(), candidate.end());
		for (int i = 0; i < t; i++) {
			int flag = 0;
			Dijkstra(s);
			long long org = dist[candidate[i]];
			long long A = dist[g];
			long long B = dist[h];
			if (A == INF && B == INF) continue;
			else if (A == INF) flag = 1;
			else if (B == INF) flag = 2;
			if (flag == 0) {
				Dijkstra(h);
				long long temp = dist[candidate[i]];
				Dijkstra(g);
				if (temp == INF && dist[candidate[i]] == INF) continue;
				else if (temp == INF) {
					if (B + dist[candidate[i]] + V == org) cout << candidate[i] << " ";
				}
				else if (dist[candidate[i]] == INF) {
					if (A + temp + V == org) cout << candidate[i] << " ";
				}
				else {
					if (min(A + temp + V, B + dist[candidate[i]] + V) == org) cout << candidate[i] << " ";
				}
			}
			else if (flag == 1) {
				Dijkstra(g);
				if (dist[candidate[i]] == INF) continue;
				else if (B + dist[candidate[i]] + V == org) cout << candidate[i] << " ";
			}
			else if (flag == 2) {
				Dijkstra(h);
				if (dist[candidate[i]] == INF) continue;
				else if (A + dist[candidate[i]] + V == org) cout << candidate[i] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}

void Dijkstra(long long start) {
	priority_queue <pair <long long, long long>, vector<pair<long long, long long>>, cmp> pq;
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[start] = 0;
	pq.push({ start, 0 });
	while (pq.size()) {
		long long idx = pq.top().first;
		pq.pop();
		for (int i = 0; i < graph[idx].size(); i++) {
			if (dist[graph[idx][i].first] > dist[idx] + graph[idx][i].second) {
				dist[graph[idx][i].first] = dist[idx] + graph[idx][i].second;
				pq.push({ graph[idx][i].first,dist[graph[idx][i].first] });
			}
		}
	}
}