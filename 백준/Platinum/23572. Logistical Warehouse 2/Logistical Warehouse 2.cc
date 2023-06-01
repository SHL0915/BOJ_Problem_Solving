#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, cnt;
vector <int> tree[100005];
int mark[100005];

int DFS(int node);

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1);

	cout << cnt + 1;
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

	for (int next : tree[node]) {
		if (mark[next]) continue;
		pq.push(DFS(next) + 1);
	}

	while (pq.size() >= 2) {
		int a = pq.top(); pq.pop();
		int b = pq.top();
		if (a + b > 2 * K) cnt++;
		else {
			pq.push(a);
			break;
		}
	}

	return pq.top();
}