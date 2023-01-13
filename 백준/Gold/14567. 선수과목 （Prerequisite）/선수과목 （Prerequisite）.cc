#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
vector <int> graph[1001];
int in_degree[1001];
int ans[1001];
queue <int> q;

void Topology();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		in_degree[b] ++;
	}
	Topology();
	for (int i = 1; i <= N; i++) cout << ans[i] << " ";
	return 0;
}

void Topology() {
	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
			ans[i] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		int now = q.front();
		q.pop();
		for (int j = 0; j < graph[now].size(); j++) {
			if (--in_degree[graph[now][j]] == 0) {
				ans[graph[now][j]] = ans[now] + 1;
				q.push(graph[now][j]);
			}
		}
	}
	return;
}