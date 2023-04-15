#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, ans;
ll arr[200001];
vector <pii> graph[200001];
int in_degree[200001];
int mark[200001];

void Topology();
void DFS(int node);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		ll a, b;
		cin >> a >> b;
		in_degree[a]++;
		graph[i].push_back({a,b});
	}

	Topology();
	cout << ans;
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

void Topology() {
	queue <int> q;
	for (int i = 1; i <= N; i++) if (in_degree[i] == 0) q.push(i);

	while (q.size()) {
		int f = q.front(); q.pop();
		mark[f] = 1;
		for (int i = 0; i < graph[f].size(); i++) {
			int next = graph[f][i].first;
			in_degree[next]--;
			ans += max(graph[f][i].second - arr[f], 0LL);
			arr[f] += max(graph[f][i].second - arr[f], 0LL);
			arr[next] += graph[f][i].second;
			if (in_degree[next] == 0) q.push(next);
		}
	}

	priority_queue <pii, vector <pii>, greater<>> pq;
	for (int i = 1; i <= N; i++) {
		if (mark[i] == 0) {
			ll cost = max(graph[i].front().second - arr[i], 0LL);
			pq.push({ cost, i });
		}
	}

	while (pq.size()) {
		pii t = pq.top(); pq.pop();
		if (mark[t.second]) continue;
		DFS(t.second);
	}

	return;
}

void DFS(int node) {
	if (mark[node]) return;
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i].first;
		ans += max(graph[node][i].second - arr[node], 0LL);
		arr[node] += max(graph[node][i].second - arr[node], 0LL);
		arr[next] += graph[node][i].second;
		DFS(next);
	}
	return;
}