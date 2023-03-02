#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, Q, ans, cnt;
vector <int> graph[222223];
int par[222223][21], level[222223];
int arr[222223];
pii pp = { INF, INF };

void pre(int node, int p, int lv);
int LCA(int a, int b);
void DFS(int node, int p);

void solve() {
	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	pre(1, 1, 1);

	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		arr[a]++;
		arr[b]++;
		arr[LCA(a, b)] -= 2;
	}	

	DFS(1, 0);

	for (int i = 1; i <= N; i++) {
		if (arr[i] > ans) {
			ans = arr[i];
			pp = { min(i, par[i][0]), max(i, par[i][0]) };
		}
		else if (arr[i] == ans) pp = min(pp, make_pair(min(i, par[i][0]), max(i, par[i][0])));
	}

	cout << pp.first << " " << pp.second << " " << ans;
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

void pre(int node, int p, int lv) {
	cnt++;
	level[node] = lv;
	par[node][0] = p;
	for (int i = 1; i <= 20; i++) par[node][i] = par[par[node][i - 1]][i - 1];
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (next == p) continue;
		pre(next, node, lv + 1);
	}
	return;
}

int LCA(int a, int b) {
	if (level[a] < level[b]) swap(a, b);
	if (level[a] != level[b]) {
		for (int i = 20; i >= 0; i--) {
			if (level[par[a][i]] >= level[b]) a = par[a][i];
		}
	}
	int ret = a;
	if (a != b) {
		for (int i = 20; i >= 0; i--) {
			if (par[a][i] != par[b][i]) {
				a = par[a][i];
				b = par[b][i];
			}
			ret = par[a][i];
		}
	}
	return ret;
}

void DFS(int node, int p) {
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (next == p) continue;	
		DFS(next, node);
		arr[node] += arr[next];
	}
	return;
}