#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

struct cmp {
	bool operator() (pair<pii, int> A, pair<pii, int> B) {
		if (A.first.first == B.first.first) return A.first.second < B.first.second;
		return A.first.first > B.first.first;
	}
};

int N, M, cnt;
vector <pii> graph[200001];
ll arr[200001];
pii dist[200001];
vector <int> path[200001], ans;

void Dijkstra(int start);
void DFS(int node);
int compare(pii A, pii B);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		cnt += arr[i];
	}
	Dijkstra(1);
	if (dist[N].second < cnt) {
		cout << -1;
		return;
	}
	DFS(N);
	cout << ans.size() << '\n';
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void Dijkstra(int start) {
	priority_queue <pair<pii, int>, vector<pair<pii, int>>, cmp> pq;
	for (int i = 1; i <= N; i++) dist[i].first = INF;
	dist[start] = { 0, arr[start] };
	pq.push({ {0, arr[start]}, start });
	while (pq.size()) {
		pii val = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (compare(dist[now], val) == 1) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			pii next_val = { val.first + graph[now][i].second, val.second + arr[next] };
			if (compare(dist[next], next_val) == -1) {
				path[next].clear();
				path[next].push_back(now);
				dist[next] = next_val;
				pq.push({ next_val, next });
			}
			else if (compare(dist[next], next_val) == 0) path[next].push_back(now);
		}
	}
}

void DFS(int node) {
	ans.push_back(node);
	if (path[node].size()) DFS(path[node][0]);
	return;
}

int compare(pii A, pii B) {
	if (A.first == B.first && A.second == B.second) return 0;
	else if (A.first == B.first) {
		if (A.second > B.second) return 1;
		else return -1;
	}
	else {
		if (A.first < B.first) return 1;
		else return -1;
	}
}