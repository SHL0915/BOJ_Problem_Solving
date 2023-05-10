#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;

int N, K, H, M;
pii arr[1005];
pii hole[55], mouse[305];
vector <int> graph[305];
int cap[305][305], flow[305][305];
int level[305], mark[305];

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);
int cross(pii a, pii b, pii c, pii d);
void add_edge(int u, int v, int c);
int Dinic(int S, int E);
int DFS(int S, int E, int f);
int BFS(int S, int E);

void solve() {
	cin >> N >> K >> H >> M;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 0; i < H; i++) cin >> hole[i].first >> hole[i].second;
	for (int i = 0; i < M; i++) cin >> mouse[i].first >> mouse[i].second;

	for (int i = 0; i < M; i++) {
		add_edge(0, i + 1, 1);
		for (int j = 0; j < H; j++) {
			int flag = 0;
			for (int k = 0; k < N; k++) {
				if (ccw(arr[k], arr[(k + 1) % N], hole[j]) == 0 && hole[j].first >= min(arr[k].first, arr[(k + 1) % N].first) && hole[j].first <= max(arr[k].first, arr[(k + 1) % N].first)) continue;
				flag |= cross(mouse[i], hole[j], arr[k], arr[(k + 1) % N]);
			}
			if (flag) continue;
			add_edge(i + 1, M + j + 1, 1);
		}		
	}

	for (int i = 0; i < H; i++) add_edge(M + i + 1, M + H + 1, K);

	int res = Dinic(0, M + H + 1);
	if (res == M) cout << "Possible";
	else cout << "Impossible";

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

ll ccw(pii a, pii b, pii c) {
	pii u = sub(b, a);
	pii v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
}

int cross(pii a, pii b, pii c, pii d) {
	ll ccw1 = ccw(a, b, c) * ccw(a, b, d);
	ll ccw2 = ccw(c, d, a) * ccw(c, d, b);
	if (ccw1 == 0 && ccw2 == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (a <= d && b >= c) return 1;
		else return 0;
	}
	else if (ccw1 <= 0 && ccw2 <= 0) return 1;
	else return 0;
}

void add_edge(int u, int v, int c) {
	graph[u].push_back(v);
	graph[v].push_back(u);
	cap[u][v] = c;
	return;
}

int Dinic(int S, int E) {
	int ret = 0;
	while (BFS(S, E)) {
		memset(mark, 0, sizeof(mark));
		while (1) {
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
			int ret = DFS(next, E, min(cap[S][next] - flow[S][next], f));
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
	queue <int> q;

	q.push(S);
	level[S] = 0;
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
