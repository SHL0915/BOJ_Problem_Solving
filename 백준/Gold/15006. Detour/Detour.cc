#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
vector <pii> graph[100001];
ll dist[100001];
vector <int> ans;
map <pii, int> dell;
int mark[100001];

void Dijkstra(int start);
void DFS(int node);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	Dijkstra(1);
	DFS(0);

	cout << "impossible";
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

void Dijkstra(int start) {
	memset(dist, INF, sizeof(dist));
	priority_queue <pii, vector<pii>, greater<>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (pq.size()) {
		pii t = pq.top(); pq.pop();
		ll now = t.second;
		ll val = t.first;
		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			ll next = graph[now][i].first;
			ll next_val = val + graph[now][i].second;
			if (dist[next] > next_val) {
				dist[next] = next_val;
				pq.push({ next_val, next });
			}
		}
	}
	return;
}

void DFS(int node) {
	if (mark[node]) return;
	mark[node] = 1;

	ans.push_back(node);
	if (node == 1) {
		cout << ans.size() << " ";
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
		exit(0);
	}

	ll val = INF;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i].first;
		val = min(val, dist[next] + graph[node][i].second);
	}

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i].first;
		if (dist[next] + graph[node][i].second == val) continue;
		DFS(next);
	}
	ans.pop_back();

	return;
}