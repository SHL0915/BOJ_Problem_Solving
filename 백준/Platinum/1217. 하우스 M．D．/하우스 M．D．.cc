#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt, id_cnt;
vector <int> graph[40005];
int par[40005], id[40005];
stack <int> st;

void init();
int convert(int a);
int DFS(int node);

void solve() {
	init();
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		graph[convert(a)].push_back(convert(-b));
		graph[convert(b)].push_back(convert(-a));
	}

	for (int i = 1; i <= 2 * M; i++) if (par[i] == 0) DFS(i);

	for (int i = 1; i <= M; i++) {
		if (id[convert(i)] != id[convert(-i)]) {
			cout << 1 << '\n';
			return;
		}
	}

	cout << 0 << '\n';
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
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		solve();
	}
	return 0;
}

void init() {
	cnt = 0; id_cnt = 0;
	for (int i = 1; i <= 2 * M; i++) {
		graph[i].clear();
		id[i] = 0;
		par[i] = 0;
	}
	while (st.size()) st.pop();
	return;
}

int convert(int a) {
	if (a > 0) return a * 2 - 1;
	else return -a * 2;
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

	if (ret == node) {
		id_cnt++;
		while (1) {
			int t = st.top(); st.pop();
			id[t] = id_cnt;
			if (t == node) break;
		}
	}

	return ret;
}