#include <bits/stdc++.h>
using namespace std;

int N, M;
vector <pair<int, long long>> graph[101];
int in_degree[101];
long long table[101];
queue <int> q;

void Topological();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int X, Y, K;
		cin >> X >> Y >> K;
		graph[X].push_back({ Y,K });
		in_degree[Y]++;
	}
	Topological();
	for (int i = 1; i <= N; i++) {
		if (graph[i].size() == 0) cout << i << " " << table[i] << '\n';		
	}
	return 0;
}

void Topological() {
	for (int i = 1; i <= N; i++) if (in_degree[i] == 0) q.push(i);
	table[N] = 1;
	for (int i = 0; i < N; i++) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			table[next] += table[now] * graph[now][i].second;
			if (--in_degree[next] == 0) q.push(next);
		}
	}
}