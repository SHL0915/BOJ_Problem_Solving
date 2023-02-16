#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
vector <int> graph[405];
int cap[405][405];
int flow[405][405];
int mark[405];

int maxFlow(int s, int e);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			a += N;
			graph[i].push_back(a);
			graph[a].push_back(i);
			cap[i][a] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		graph[0].push_back(i);
		graph[i].push_back(0);
		cap[0][i] = 1;
	}
	for (int i = N + 1; i <= N + M; i++) {
		graph[i].push_back(N + M + 1);
		graph[N + M + 1].push_back(i);
		cap[i][N + M + 1] = 1;
	}
	cout << maxFlow(0, N + M + 1);
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

int maxFlow(int s, int e) {
	int ret = 0;
	while (1) {
		memset(mark, -1, sizeof(mark));
		queue <int > q;
		q.push(s);
		while (q.size()) {
			int now = q.front(); q.pop();
			for (int i = 0; i < graph[now].size(); i++) {
				int next = graph[now][i];
				if (cap[now][next] - flow[now][next] > 0 && mark[next] == -1) {
					q.push(next);
					mark[next] = now;
					if (next == e) break;
				}
			}
		}
		if (mark[e] == -1) break;
		int val = INF;
		for (int i = e; i != s; i = mark[i]) val = min(val, cap[mark[i]][i] - flow[mark[i]][i]);
		for (int i = e; i != s; i = mark[i]) {
			flow[mark[i]][i] += val;
			flow[i][mark[i]] -= val;
		}
		ret += val;
	}
	return ret;
}