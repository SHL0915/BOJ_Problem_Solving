#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef pair<pair<int, int>, int> piii;

int N, M;
double ans = INF;
int dist[201][201];
vector <piii> graph;

int absol(int A) {
	if (A >= 0) return A;
	else return -1 * A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(1);
	cin >> N >> M;
	memset(dist, INF, sizeof(dist));
	for (int i = 1; i <= N; i++) dist[i][i] = 0;
	for (int i = 0; i < M; i++) {
		int S, E, L;
		cin >> S >> E >> L;
		graph.push_back({ {S,E},L });
		dist[S][E] = min(dist[S][E], L);
		dist[E][S] = min(dist[E][S], L);
	}	
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		double temp = 0;
		for (int j = 0; j < graph.size(); j++) {
			int S = graph[j].first.first;
			int E = graph[j].first.second;
			int L = graph[j].second;
			double t = min(dist[i][S], dist[i][E]);
			if (absol(dist[i][S] - dist[i][E]) >= L) t += L;
			else {
				t += absol(dist[i][S] - dist[i][E]);
				L -= absol(dist[i][S] - dist[i][E]);
				t += L / 2.0;
			}
			temp = max(temp, t);
		}
		ans = min(ans, temp);
	}
	cout << ans;
	return 0;
}