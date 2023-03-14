#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
int arr[1001];
vector <pii> graph[1001];
int dist[1001];
int cnt[1001];

void Dijkstra(int start);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a; cin >> a;
			if (a) graph[i].push_back({ j,a });
		}
	}

	Dijkstra(0);

	cout << cnt[M] << " " << dist[M];
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
	memset(cnt, INF, sizeof(cnt));
	priority_queue <pair<pii, int>, vector<pair<pii, int>>, greater<>> pq;
	dist[start] = 0;
	cnt[start] = 0;
	pq.push({ {0,0}, start });
	while (pq.size()) {
		pair<pii, int> t = pq.top(); pq.pop();
		int now = t.second;
		int val = t.first.second;
		int c = t.first.first;
		if (cnt[now] < c) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int new_val = val + graph[now][i].second;
			int new_cnt = c + (arr[now] != arr[next]);
			if (cnt[next] > new_cnt || (cnt[next] == new_cnt && dist[next] > new_val)) {
				cnt[next] = new_cnt;
				dist[next] = new_val;
				pq.push({ {new_cnt, new_val}, next });
			}
		}
	}
	return;
}