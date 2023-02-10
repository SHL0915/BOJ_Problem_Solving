#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt;
int parent[100001];
int sz[100001];
map <pii, int> m;
pair<pii, pii> edge_time[100001];
vector <pair<pii, pii>> edge;
pii query[100001];
vector <vector<pii>> tree;
stack <pair<pii, int>> s;

void update(int node, int start, int end, int left, int right, pii val);
void DnC(int left, int right, int node);
int Find(int a);
int Union(int a, int b);
void rollback(int cnt);

void solve() {
	cin >> N >> M;
	tree.resize(4 * M);
	for (int i = 1; i <= M; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b > c) swap(b, c);
		if (a == 1) {
			m[{b, c}] = i;
			edge_time[i] = { {b,c}, {cnt + 1, -1} };
		}
		else if (a == 2) {
			int idx = m[{b, c}];
			edge_time[idx].second.second = cnt;
			edge.push_back(edge_time[idx]);
		}
		else query[++cnt] = { b,c };
	}

	for (int i = 1; i <= M; i++) {
		if (edge_time[i].second.second == -1) {
			edge_time[i].second.second = cnt;
			edge.push_back(edge_time[i]);
		}
	}
	for (int i = 0; i < edge.size(); i++) update(1, 1, cnt, edge[i].second.first, edge[i].second.second, edge[i].first);

	DnC(1, cnt, 1);
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

void update(int node, int start, int end, int left, int right, pii val) {
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		tree[node].push_back(val);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, val);
	update(node * 2 + 1, mid + 1, end, left, right, val);
	return;
}

void DnC(int left, int right, int node) {
	int cnt = 0;
	for (int i = 0; i < tree[node].size(); i++) cnt += Union(tree[node][i].first, tree[node][i].second);
	if (left == right) {
		int ret = (Find(query[left].first) == Find(query[left].second));
		cout << ret << '\n';
		rollback(cnt);
		return;
	}
	int mid = (left + right) / 2;
	DnC(left, mid, node * 2);
	DnC(mid + 1, right, node * 2 + 1);
	rollback(cnt);
	return;
}

int Find(int a) {
	if (a == parent[a]) return a;
	else return Find(parent[a]);
}

int Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return 0;
	if (sz[a] < sz[b]) swap(a, b);
	parent[b] = a;
	if (sz[a] == sz[b]) {
		sz[a]++;
		s.push({ {a,b},1 });
	}
	else s.push({ {a,b},0 });
	return 1;
}

void rollback(int cnt) {
	while (cnt--) {
		pair<pii, int> t = s.top();
		s.pop();
		int a = t.first.first;
		int b = t.first.second;
		int type = t.second;
		parent[b] = b;
		if (type == 1) sz[a]--;
	}
	return;
}