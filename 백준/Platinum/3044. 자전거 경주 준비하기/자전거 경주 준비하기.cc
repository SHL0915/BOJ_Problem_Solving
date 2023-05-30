#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000000LL;

int N, M, cnt, id_cnt;
vector <int> graph[10005];
vector <int> topograph[10005];
int in_degree[10005], par[10005], id[10005], mark[10005];
ll table[10005];
vector <pii> edge;
stack <int> st;

int DFS(int node);
int DP(int node);
void chk(int node);
void Topology();

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		edge.push_back({ a,b });
	}

	chk(1);
	if (mark[2] == 0) {
		cout << 0;
		return;
	}

	memset(mark, -1, sizeof(mark));

	for (int i = 1; i <= N; i++) if (par[i] == 0) DFS(i);
	
	DP(1);

	for (int i = 0; i < M; i++) {
		int a = edge[i].first, b = edge[i].second;
		if (mark[a] == 1 && mark[b] == 1) {
			topograph[a].push_back(b);
			in_degree[b]++;
		}
	}

	cnt = 0;

	for (int i = 1; i <= N; i++) {
		if (mark[i] == 1) cnt++;
	}

	Topology();

	if (table[2] < mod) cout << table[2];
	else {
		table[2] %= mod;
		string ans = "";

		while (table[2]) {
			ans = (char)('0' + table[2] % 10) + ans;
			table[2] /= 10;
		}

		while (ans.length() < 9) ans = '0' + ans;

		cout << ans;
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

void chk(int node) {
	if (mark[node]) return;
	mark[node] = 1;
	for (int next : graph[node]) chk(next);
	return;
}

int DP(int node) {
	int& ret = mark[node];
	if (node == 2) return ret = 1;
	if (ret != -1) return ret;
	ret = 0;
	for (int next : graph[node]) ret |= DP(next);
	return ret;
}

int DFS(int node) {
	par[node] = ++cnt;
	int ret = cnt;
	st.push(node);

	for (int next : graph[node]) {
		if (par[next] == 0) ret = min(ret, DFS(next));
		else if (id[next] == 0) ret = min(ret, par[next]);
	}

	if (ret == par[node]) {
		id_cnt++;
		while (st.size()) {
			int t = st.top(); st.pop();
			id[t] = id_cnt;
			if (t == node) break;
		}
	}

	return ret;
}

void Topology() {
	queue <int> q;
	for (int i = 1; i <= N; i++) {
		if (mark[i] == 1 && in_degree[i] == 0) {
			q.push(i);
			table[i] = 1;
		}
	}

	for (int i = 0; i < cnt; i++) {
		if (q.size() == 0) {
			cout << "inf";
			exit(0);
		}
		int now = q.front(); q.pop();
		for (int next : topograph[now]) {
			table[next] += table[now];
			if (table[next] >= mod) {
				table[next] %= mod;
				table[next] += mod;
			}
			if (--in_degree[next] == 0) q.push(next);
		}
	}

	return;
}