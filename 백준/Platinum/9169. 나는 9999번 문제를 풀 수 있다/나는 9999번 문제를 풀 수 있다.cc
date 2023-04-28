#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
vector <int> graph[305];
int arr[305];
int cap[305][305], flow[305][305];
int mark[305], level[305];

int Dinic(int S, int E);
int DFS(int S, int E, int f);
int BFS(int S, int E);

void solve() {
	cin >> N >> M;
	if (N == 0 && M == 0) exit(0);
	memset(cap, 0, sizeof(cap));
	memset(flow, 0, sizeof(flow));
	graph[0].clear();
	graph[N + 1].clear();
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		graph[i].clear();
		if (arr[i] == 0) {
			graph[0].push_back(i);
			graph[i].push_back(0);
			cap[0][i] = 1;
		}
		else {
			graph[N + 1].push_back(i);
			graph[i].push_back(N + 1);
			cap[i][N + 1] = 1;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		cap[a][b] = 1;
		cap[b][a] = 1;
	}

	cout << Dinic(0, N + 1) << '\n';
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
	while (1) solve();
	return 0;
}

int Dinic(int S, int E) {
	int ret = 0;

	while (BFS(S, E)) {
		memset(mark, 0, sizeof(mark));
		while(1){
            int f = DFS(S, E, INF);
		    if (f) ret += f;
		    else break;
        }
	}

	return ret;
}

int DFS(int S, int E, int f) {
	if (S == E) return f;
	
	for (int& i = mark[S]; i < graph[S].size(); i++) {
		int next = graph[S][i];
		if (level[next] == level[S] + 1 && cap[S][next] - flow[S][next] > 0) {
			int ret = DFS(next, E, min(f, cap[S][next] - flow[S][next]));
			if (ret) {
				flow[S][next] += ret;
				flow[next][S] -= ret;
				return ret;
			}
		}
	}

	return 0;
}

int BFS(int S, int E) {
	memset(level, -1, sizeof(level));
	level[S] = 0;
	
	queue <int> q;
	q.push(S);

	while (q.size()) {
		int f = q.front(); q.pop();
		for (int i = 0; i < graph[f].size(); i++) {
			int next = graph[f][i];
			if (level[next] == -1 && cap[f][next] - flow[f][next] > 0) {
				level[next] = level[f] + 1;
				q.push(next);
			}
		}
	}

	return level[E] != -1;
}