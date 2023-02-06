#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, M, root, ans;
vector <int> tree[100001];
ll cost[100001];
ll arr[100001];
ll sum[100001];
priority_queue <ll> pq[100001];

void DFS(int node);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		if (a == 0) root = i;
		tree[a].push_back(i);
		cin >> cost[i] >> arr[i];
	}
	DFS(root);
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
	for (int i = 0; i < tree[node].size(); i++) DFS(tree[node][i]);	
	pq[node].push(cost[node]);
	sum[node] += cost[node];
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (pq[node].size() < pq[next].size()) {
			pq[node].swap(pq[next]);
			swap(sum[node], sum[next]);
		}
		while (pq[next].size()) {
			pq[node].push(pq[next].top());
			sum[node] += pq[next].top();
			pq[next].pop();
		}
	}
	while (pq[node].size()) {
		if (sum[node] <= M) break;
		sum[node] -= pq[node].top();
		pq[node].pop();
	}
	ans = max(ans, arr[node] * (ll)pq[node].size());
	return;
}