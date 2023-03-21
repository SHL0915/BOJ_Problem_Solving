#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 100001;
const int INF = 0x3f3f3f3f;

int N, M, cnt;
int color[SZ], mark[SZ], level[SZ], parent[SZ], sz[SZ], id[SZ], head[SZ], rev[SZ];
vector <int> tree[SZ], graph[SZ];
pii seg[SZ * 2 + 5];

void Find_Child(int node);
void DFS(int node, int lv);
void ETT(int node);
void update(int pos, pii val);
pii query(int a, int b);
pii seg_query(int l, int r);

void solve() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	Find_Child(1);
	DFS(1, 1);

	head[1] = 1;
	ETT(1);

	for (int i = 1; i <= N; i++) {
		update(i, { INF,i });
		rev[id[i]] = i;
	}
				
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		b = id[b];
		if (a == 1) {
			if (color[b]) update(b, { INF, rev[b]});
			else update(b, { level[rev[b]], rev[b]});
			color[b] ^= 1;
		}
		else {
			pii ans = query(1, rev[b]);
			if (ans.first == INF) cout << -1 << '\n';
			else cout << ans.second << '\n';
		}
	}

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

void Find_Child(int node) {
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (mark[next]) continue;
		tree[node].push_back(graph[node][i]);
		Find_Child(next);
	}
	return;
}

void DFS(int node, int lv) {
	sz[node] = 1;
	level[node] = lv;
	for (int i = 0; i < tree[node].size(); i++) {
		int& next = tree[node][i];
		parent[next] = node;
		DFS(next, lv + 1);
		sz[node] += sz[next];
		if (sz[next] > sz[tree[node][0]]) swap(next, tree[node][0]);
	}
	return;
}

void ETT(int node) {
	cnt++;
	id[node] = cnt;
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (i == 0) head[next] = head[node];
		else head[next] = next;
		ETT(next);
	}
	return;
}

void update(int pos, pii val) {
	for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = min(seg[pos], seg[pos ^ 1]);
	return;
}

pii query(int a, int b) {
	pii ret = { INF, INF };
	while (head[a] != head[b]) {
		if (level[head[a]] < level[head[b]]) swap(a, b);
		int st = head[a];
		ret = min(ret, seg_query(id[st], id[a] + 1));
		a = parent[st];
	}
	if (level[a] > level[b]) swap(a, b);
	ret = min(ret, seg_query(id[a], id[b] + 1));
	return ret;
}

pii seg_query(int l, int r) {
	pii ret = { INF ,INF };
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = min(ret, seg[l++]);
		if (r & 1) ret = min(ret, seg[--r]);
	}
	return ret;
}