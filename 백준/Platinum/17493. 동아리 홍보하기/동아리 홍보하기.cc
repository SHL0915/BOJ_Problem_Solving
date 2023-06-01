#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt;
vector <int> forest[200005];
int mark[200005];

int DFS(int node);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		forest[a].push_back(b);
		forest[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (mark[i] == 0) {
			cnt++;
			DFS(i);
		}
	}

	cout << cnt;
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

int DFS(int node) {
	mark[node] = 1;

	priority_queue <int> pq;
	pq.push(0);

	for (int next : forest[node]) {
		if (mark[next]) continue;
		pq.push(DFS(next) + 1);
	}

	while (pq.size() >= 2) {
		int a = pq.top(); pq.pop();
		int b = pq.top();
		if (a + b > 2) cnt++;
		else {
			pq.push(a);
			break;
		}
	}

	return pq.top();
}