#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q, cnt;
int arr[30001];
int parent[30001];
int table[30001][21];
int level[30001];
int mark[30001];
pii ETT[30001];
vector <int> graph[30001];
pair<int, pii> q[300001];
vector <int> tree;

int Find(int a);
void Union(int a, int b);
void DFS(int node, int par);
void pre(int node, int par, int lv);
int LCA(int a, int b);
void update(int node, int start, int end, int idx, int val);
int query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N;
	tree.resize(8 * N);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		parent[i] = i;
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		string s;
		int a, b;
		cin >> s >> a >> b;
		if (s == "bridge") {
			q[i] = { 0, {a,b} };
			if (Find(a) == Find(b)) continue;
			Union(a, b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		else if (s == "penguins") q[i] = { 1, {a,b} };		
		else q[i] = { 2, {a,b} };		
	}
	for (int i = 1; i <= N; i++) {
		if (mark[i] == 0) DFS(i, -1);		
	}
	memset(mark, 0, sizeof(mark));
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		if (mark[i] == 0) pre(i, i, 1);
	}
	for (int i = 1; i <= N; i++) {
		update(1, 1, 2 * N, ETT[i].first, arr[i]);
		update(1, 1, 2 * N, ETT[i].second, -arr[i]);
	}
	for (int i = 0; i < Q; i++) {
		int a, b, c;
		a = q[i].first;
		b = q[i].second.first;
		c = q[i].second.second;
		if (a == 0) {
			if (Find(b) == Find(c)) cout << "no\n";
			else {
				Union(b, c);
				cout << "yes\n";
			}
		}
		else if (a == 1) {
			update(1, 1, 2 * N, ETT[b].first, c);
			update(1, 1, 2 * N, ETT[b].second, -c);
		}
		else {
			if (Find(b) == Find(c)) {
				int lca = LCA(b, c);
				cout << query(1, 1, 2 * N, ETT[lca].first, ETT[b].first) + query(1, 1, 2 * N, ETT[lca].first, ETT[c].first) - query(1, 1, 2 * N, ETT[lca].first, ETT[lca].first) << '\n';
			}
			else cout << "impossible\n";
		}
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

int Find(int a) {
	if (parent[a] == a) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) parent[a] = b;
	else parent[b] = a;
	return;
}

void DFS(int node, int par) {
	mark[node] = 1;
	cnt++;
	ETT[node].first = cnt;
	for (int i = 0; i < graph[node].size(); i++) {
		if (graph[node][i] == par) continue;
		DFS(graph[node][i], node);
	}
	cnt++;
	ETT[node].second = cnt;
	return;
}

void pre(int node, int par, int lv) {
	mark[node] = 1;
	level[node] = lv;
	table[node][0] = par;
	for (int i = 1; i <= 20; i++) table[node][i] = table[table[node][i - 1]][i - 1];
	for (int i = 0; i < graph[node].size(); i++) {
		if (graph[node][i] == par) continue;
		pre(graph[node][i], node, lv + 1);
	}
	return;
}

int LCA(int a, int b) {
	if (level[a] < level[b]) swap(a, b);
	if (level[a] != level[b]) {
		for (int i = 20; i >= 0; i--) {
			if (level[table[a][i]] >= level[b]) a = table[a][i];
		}
	}
	int ret = a;
	if (a != b) {
		for (int i = 20; i >= 0; i--) {
			if (table[a][i] != table[b][i]) {
				a = table[a][i];
				b = table[b][i];
			}
			ret = table[a][i];
		}
	}
	return ret;
}

void update(int node, int start, int end, int idx, int val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}