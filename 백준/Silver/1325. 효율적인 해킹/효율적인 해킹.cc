#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt;
vector <int> graph[10001];
int mark[10001];
pii ans[10001];

void DFS(int node);
bool cmp(pii a, pii b);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		memset(mark, 0, sizeof(mark));
		cnt = 0;
		DFS(i);
		ans[i] = { cnt, i };
	}
	sort(ans + 1, ans + N + 1, cmp);
	for (int i = 1; i <= N; i++) {
		if (ans[i].first == ans[1].first) cout << ans[i].second << ' ';
		else break;
	}
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

void DFS(int node) {
	if (mark[node]) return;
	mark[node] = 1;
	cnt++;
	for (int i = 0; i < graph[node].size(); i++) DFS(graph[node][i]);
	return;
}

bool cmp(pii a, pii b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}