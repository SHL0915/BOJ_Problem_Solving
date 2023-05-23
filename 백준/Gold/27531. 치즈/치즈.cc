#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
vector <int> graph[200005];
vector <int> path;
pair<pii, int> arr[200005];
int mark[200005], table[200005][2][2];

void DFS(int node);
int DP(int now, int a, int b);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
	sort(arr + 1, arr + N + 1, [&](pair<pii, int> a, pair<pii, int> b) {
		return a.first.first < b.first.first;
		});

	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		graph[i].push_back(arr[i].first.second);
		graph[arr[i].first.second].push_back(i);
	}

	for (int i = 1; i <= N; i++) {
		if (mark[i]) continue;
		path.clear();
		DFS(i);

		if (path.size() == 1) {
			ans += arr[path[0]].second;
			continue;
		}

		for (int i = 0; i < path.size(); i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) table[i][j][k] = -1;
			}
		}

		ans += min(DP(0, 0, 0), DP(0, 1, 1));
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

void DFS(int node) {
	if (mark[node]) return;
	mark[node] = 1;
	path.push_back(node);
	for (int i : graph[node]) DFS(i);
	return;
}

int DP(int now, int a, int b) {
	if (now == path.size() - 1) {
		if (a) return arr[path[now]].second;
		else {
			if (b == 0) return arr[path[now]].second;
			else return 0;
		}
	}
	int& ret = table[now][a][b];
	if (ret != -1) return ret;
	ret = INF;

	if (a == 0) ret = min(ret, DP(now + 1, 1, b));
	else {
		ret = min(ret, arr[path[now]].second + DP(now + 1, 1, b));
		ret = min(ret, arr[path[now]].second + DP(now + 1, 0, b));
	}

	return ret;
}