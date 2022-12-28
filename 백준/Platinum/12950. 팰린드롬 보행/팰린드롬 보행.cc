#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, M;
vector <int> graph[20][26];
int table[20][20];
int adj[20][20];

int DP(int start, int end);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		graph[a][c - 'a'].push_back(b);
		graph[b][c - 'a'].push_back(a);
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	memset(table, -1, sizeof(table));
	if (DP(0, 1) == INF) cout << -1;
	else cout << DP(0, 1);
	return 0;
}

int DP(int start, int end) {
	if (start == end) return 0;
	if (adj[start][end] == 1) return 1;
	int& ret = table[start][end];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < graph[start][i].size(); j++) {
			for (int k = 0; k < graph[end][i].size(); k++) {
				int s_next = graph[start][i][j];
				int e_next = graph[end][i][k];
				ret = min(ret, 2 + DP(s_next, e_next));
			}			
		}
	}
	return ret;
}