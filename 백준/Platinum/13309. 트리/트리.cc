#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 200001;

int N, Q, cnt;
vector <int> tree[SZ];
int parent[SZ], level[SZ], sz[SZ], id[SZ], head[SZ];
int seg[SZ * 2 + 5];

void DFS(int node, int lv);
void ETT(int node);
int query(int a, int b);
void update(int pos, int val);
int seg_query(int l, int r);

void solve() {
	cin >> N >> Q;
	for (int i = 2; i <= N; i++) {
		cin >> parent[i];
		tree[parent[i]].push_back(i);
	}

	DFS(1, 1);
	
	head[1] = 1;
	ETT(1);

	for (int i = 0; i < Q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c == 0) {
			int ans = query(a, b);	
			if (ans == 0) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			int ans = query(a, b);
			if (ans == 0) {
				cout << "YES\n";
				update(id[a], 1);
			}
			else {
				cout << "NO\n";
				update(id[b], 1);
			}			
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

void DFS(int node, int lv) {
	sz[node] = 1;
	level[node] = lv;
	for (int i = 0; i < tree[node].size(); i++) {
		int& next = tree[node][i];
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

int query(int a, int b) {
	int ret = 0;
	while (head[a] != head[b]) {
		if (level[head[a]] < level[head[b]]) swap(a, b);
		int st = head[a];
		ret += seg_query(id[st], id[a] + 1);
		a = parent[st];
	}
	if (level[a] > level[b]) swap(a, b);
	ret += seg_query(id[a] + 1, id[b] + 1);
	return ret;
}

void update(int pos, int val) {
	for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
	return;
}

int seg_query(int l, int r) {
	int ret = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret += seg[l++];
		if (r & 1) ret += seg[--r];
	}
	return ret;
}