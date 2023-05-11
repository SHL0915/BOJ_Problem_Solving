#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pair <pii, int> arr[205];
vector <int> graph[205];
int mark[205];

ll sqrdist(pii a, pii b);
void DFS(int node);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ll dist = sqrdist(arr[i].first, arr[j].first);
			if (dist <= arr[i].second * arr[i].second) graph[i].push_back(j);
		}
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		memset(mark, 0, sizeof(mark));
		DFS(i);
		int cnt = 0;
		for (int j = 0; j < N; j++) if (mark[j]) cnt++;
		ans = max(ans, cnt);
	}

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

ll sqrdist(pii a, pii b) {
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return dx * dx + dy * dy;
}

void DFS(int node) {
	if (mark[node]) return;
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) DFS(graph[node][i]);
	return;
}