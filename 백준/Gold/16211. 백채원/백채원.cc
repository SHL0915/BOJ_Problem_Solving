#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

struct cmp {
	bool operator() (pair<pii, ll> a, pair<pii, int> b) {
		if (a.first.first == b.first.first) return a.first.second < b.first.second;
		else return a.first.first > b.first.first;
	}
};

int N, M, K;
vector <pii> graph[200001];
ll dist[200001];
ll mark[200001];
priority_queue <pair<pii,ll>, vector<pair<pii, ll>>, cmp> pq;

void BFS();

void solve() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	memset(dist, INF, sizeof(dist));
	memset(mark, -1, sizeof(mark));
	for (int i = 0; i < K; i++) {
		int a; cin >> a;
		dist[a] = 0;
		mark[a] = 1;
		for (int j = 0; j < graph[a].size(); j++) pq.push({ {graph[a][j].second, 1}, graph[a][j].first });
	}
	dist[1] = 0;
	mark[1] = 0;
	for (int i = 0; i < graph[1].size(); i++) {
		pq.push({ { graph[1][i].second, 0 }, graph[1][i].first });
	}
	while (pq.size()) BFS();
	int flag = 0;
	for (int i = 2; i <= N; i++) {
		if (mark[i] == 0) {
			cout << i << " ";
			flag = 1;
		}
	}
	if (flag == 0) cout << 0;
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

void BFS() {
	pair<pii, int> t = pq.top();
	pq.pop();
	ll d = t.first.first;
	ll now = t.second;
	if (dist[now] <= d) return;
	dist[now] = d;
	mark[now] = t.first.second;
	for (int i = 0; i < graph[now].size(); i++) pq.push({ {d + graph[now][i].second, t.first.second}, graph[now][i].first });
	return;
}