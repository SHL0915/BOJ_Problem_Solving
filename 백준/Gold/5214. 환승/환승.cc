#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, M;
vector <int> graph[500005];
int mark[500005];
queue <int> q;

void BFS();

void solve() {
	cin >> N >> K >> M;

	memset(mark, -1, sizeof(mark));

	if (N == 1) {
		cout << 1;
		return;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < K; j++) {
			int a; cin >> a;
			graph[N + i].push_back(a);
			graph[a].push_back(N + i);
			if (a == 1) {
				q.push(N + i);
				mark[N + i] = 0;
			}
		}
	}

	while (q.size()) BFS();

	cout << -1;
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
	int now = q.front(); q.pop();

	if (now == N) {
		cout << mark[now] + 1;
		exit(0);
	}

	for (int next : graph[now]) {
		if (mark[next] != -1) continue;
		if (next > N) mark[next] = mark[now];
		else mark[next] = mark[now] + 1;
		q.push(next);
	}
}