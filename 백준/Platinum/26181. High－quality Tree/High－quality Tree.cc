#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector <int> tree[200001];
int child[200001][2];
int level[200001];
int mark[200001];

void DFS(int node, int par);
void find_lv(int node);
void marking(int node, int lv, int target);
void elminate(int node);

void solve() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1, 1);
	find_lv(1);

	int ans = 0;
	for (int i = 1; i <= N; i++) ans += mark[i];

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

void DFS(int node, int par) {
	int cnt = 0;
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (next == par) continue;
		DFS(next, node);
		child[node][cnt] = next;
		cnt++;
	}
	return;
}

void find_lv(int node) {
	level[node] = 0;
	int l = 0, r = 0;

	if (child[node][0]) {
		int next = child[node][0];
		find_lv(next);
		l = level[next] + 1;
	}
	if (child[node][1]) {
		int next = child[node][1];
		find_lv(next);
		r = level[next] + 1;
	}

	if (abs(l - r) <= 1) {
		level[node] = max(l, r);
		return;
	}
	else {
		int val = min(l, r) + 2;
		if (child[node][0]) {
			int next = child[node][0];
			marking(next, 1, val);
			l = level[next] + 1;
		}
		if (child[node][1]) {
			int next = child[node][1];
			marking(next, 1, val);
			r = level[next] + 1;
		}
		level[node] = max(l, r);
		return;
	}
}

void marking(int node, int lv, int target) {
	if (lv == target) {
		level[node] = -1;
		elminate(node);
		return;
	}

	int l = 0, r = 0;
	if (child[node][0]) {
		int next = child[node][0];
		marking(next, lv + 1, target);
		l = level[next] + 1;
	}
	if (child[node][1]) {
		int next = child[node][1];
		marking(next, lv + 1, target);
		r = level[next] + 1;
	}
	level[node] = max(l, r);

	return;
}

void elminate(int node) {
	if (mark[node]) return;
	mark[node] = 1;
	if (child[node][0]) {
		int next = child[node][0];
		elminate(next);
	}
	if (child[node][1]) {
		int next = child[node][1];
		elminate(next);
	}
	return;
}