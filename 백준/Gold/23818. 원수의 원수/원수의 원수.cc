#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K, cnt;
vector <pii> graph[100001];
int color[100001];
int mark[100001];
int error[100001];

void DFS(int node, int c, int id);

void solve() {
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[b].push_back({ c,a });
		graph[c].push_back({ b,a });
	}

	for (int i = 1; i <= N; i++) {
		if (mark[i] == 0) {
			cnt++;
			DFS(i, 0, cnt);
		}
	}
	
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		if (mark[a] != mark[b]) cout << "Unknown\n";
		else {
			if (error[mark[a]]) cout << "Error\n";
			else {
				if (color[a] == color[b]) cout << "Friend\n";
				else cout << "Enemy\n";
			}
		}
	}

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void DFS(int node, int c, int id) {
	if (mark[node]) {
		if (color[node] == c) return;
		else {
			error[mark[node]] = 1;
			return;
		}
	}
	mark[node] = id;
	color[node] = c;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i].first;
		int next_c = c ^ graph[node][i].second;
		DFS(next, next_c, id);
	}
	return;
}