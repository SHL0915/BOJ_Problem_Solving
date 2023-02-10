#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct edge { int u, v, l, r; };

int N, M, t;
int parent[100001], rnk[100001];
map <pii, int> m;
edge temp[100001];
vector <edge> arr;
pii query[100001];
int ans[100001];
vector <vector<pii>> tree;
stack <pair<pii, int>> st;

void update(int node, int start, int end, int left, int right, pii val);
void DnC(int node, int start, int end);
int Find(int a);
int Union(int a, int b);
void RollBack(int k);

void solve() {
	cin >> N >> M;
	tree.resize(4 * M);
	for (int i = 1; i <= M; i++) parent[i] = i;
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b > c) swap(b, c);
		if (a == 1) {
			m[{b, c}] = i;
			temp[i] = { b,c,t + 1, -1 };
		}
		else if (a == 2) {
			int idx = m[{b, c}];
			temp[idx].r = t;
			arr.push_back(temp[idx]);
		}
		else query[++t] = { b,c };
	}
	for (int i = 1; i <= M; i++) {
		if (temp[i].r == -1) {
			temp[i].r = t;
			arr.push_back(temp[i]);
		}
	}
	for (int i = 0; i < arr.size(); i++) update(1, 1, t, arr[i].l, arr[i].r, { arr[i].u, arr[i].v });
	DnC(1, 1, t);
	for (int i = 1; i <= t; i++) cout << ans[i] << '\n';
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

void DnC(int node, int start, int end) {
	int cnt = 0;
	for (int i = 0; i < tree[node].size(); i++) cnt += Union(tree[node][i].first, tree[node][i].second);
	if (start == end) {
		ans[start] = (Find(query[start].first) == Find(query[start].second));
		RollBack(cnt);
		return;
	}
	int mid = (start + end) / 2;
	DnC(node * 2, start, mid);
	DnC(node * 2 + 1, mid + 1, end);
	RollBack(cnt);
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
	if (rnk[a] < rnk[b]) swap(a, b);
	parent[b] = a;
	st.push({ {a,b}, 0 });
	if (rnk[a] == rnk[b]) {
		rnk[a] ++;
		st.top().second = 1;
	}
	return 1;
}

void RollBack(int k) {
	while (k--) {
		pair <pii, int> t = st.top();
		st.pop();
		parent[t.first.second] = t.first.second;
		if (t.second) rnk[t.first.first]--;
	}
	return;
}