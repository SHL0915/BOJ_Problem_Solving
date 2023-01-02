#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll N, B, D, ans = INF;
vector <int> tree[111223];
ll sz[111223];
ll table[111223][33];
ll pow_2[33];

void DFS(int node, int par);
ll DP(int node, int par, int h);
ll create_tree(int h);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	pow_2[0] = 2;
	for (int i = 1; i < 33; i++) pow_2[i] = pow_2[i - 1] * 2;
	cin >> N >> B >> D;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	DFS(1, -1);
	memset(table, -1, sizeof(table));
	for (int i = 0; i < 33; i++) ans = min(ans, DP(1, -1, i));	
	cout << ans;
	return 0;
}

void DFS(int node, int par) {
	sz[node] = 1;
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (next == par) continue;
		DFS(next, node);
		sz[node] += sz[next];
	}
	return;
}

ll DP(int node, int par, int h) {
	if (h == 0) return D * (sz[node] - 1);
	ll& ret = table[node][h];
	if (ret != -1) return ret;
	priority_queue <ll, vector <ll>, greater<>> pq;
	for (int i = 0; i < tree[node].size(); i++) {
		int ch = tree[node][i];
		if (ch == par) continue;
		pq.push(DP(ch, node, h - 1) - D * sz[ch]);
	}
	ret = D * (sz[node] - 1) + 2 * create_tree(h - 1);
	if (pq.size()) {
		ll t = pq.top();
		pq.pop();
		ret = min(ret, D * (sz[node] - 1) + t + create_tree(h - 1));
		if (pq.size()) ret = min(ret, D * (sz[node] - 1) + t + pq.top());
	}	
	return ret;
}

ll create_tree(int h) {
	return B * (pow_2[h] - 1);
}