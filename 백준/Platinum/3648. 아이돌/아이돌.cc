#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt, id_cnt;
vector <int> graph[2001];
int par[2001], id[2001];
stack <int> st;

void init();
int convert(int node);
int DFS(int node);

void solve() {
	while (cin >> N >> M) {
		init();
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			graph[convert(-a)].push_back(convert(b));
			graph[convert(-b)].push_back(convert(a));
		}
		graph[convert(-1)].push_back(convert(1));
		for (int i = 1; i <= 2 * N; i++) if (par[i] == 0) DFS(i);
		int flag = 0;
		for (int i = 1; i <= N; i++) {
			if (id[convert(i)] == id[convert(-i)]) {
				flag = 1;
				break;
			}
		}
		if (flag) cout << "no\n";
		else cout << "yes\n";
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

void init() {
	cnt = 0;
	id_cnt = 0;
	for (int i = 1; i <= 2 * N; i++) {
		graph[i].clear();
		par[i] = 0;
		id[i] = 0;
	}
	return;
}

int convert(int node) {
	if (node > 0) return node * 2 - 1;
	else return -node * 2;
}

int DFS(int node) {
	par[node] = ++cnt;
	int ret = cnt;
	st.push(node);
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (par[next] == 0) ret = min(ret, DFS(next));
		else if (id[next] == 0) ret = min(ret, par[next]);
	}
	if (ret == par[node]) {
		id_cnt++;
		while (1) {
			int t = st.top();
			st.pop();
			id[t] = id_cnt;
			if (t == node) break;
		}
	}
	return ret;
}