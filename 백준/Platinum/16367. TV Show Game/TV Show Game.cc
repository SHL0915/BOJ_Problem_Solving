#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int K, N, cnt, id_cnt;
vector <int> graph[10001];
int parent[10001], id[10001], ans[10001];
vector <vector<int>> SCC;
stack <int> st;

int DFS(int node);
int convert(int node);

void solve() {
	cin >> K >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		char color;
		cin >> a >> color;
		if (color == 'B') a *= -1;
		cin >> b >> color;
		if (color == 'B') b *= -1;
		cin >> c >> color;
		if (color == 'B') c *= -1;
		graph[convert(-a)].push_back(convert(b));
		graph[convert(-a)].push_back(convert(c));
		graph[convert(-b)].push_back(convert(a));
		graph[convert(-b)].push_back(convert(c));
		graph[convert(-c)].push_back(convert(a));
		graph[convert(-c)].push_back(convert(b));
	}
	for (int i = 1; i <= 2 * K; i++) if (parent[i] == 0) DFS(i);
	for (int i = 1; i <= K; i++) {
		if (id[convert(i)] == id[convert(-i)]) {
			cout << -1;
			return;
		}
	}
	memset(ans, -1, sizeof(ans));
	for (int i = SCC.size() - 1; i >= 0; i--) {
		for (int j = 0; j < SCC[i].size(); j++) {
			int now = (SCC[i][j] + 1) / 2;
			if (ans[now] != -1) continue;
			ans[now] = (SCC[i][j] % 2) ^ 1;
		}
	}
	for (int i = 1; i <= K; i++) {
		if (ans[i]) cout << "R";
		else cout << "B";
	}

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

int DFS(int node) {
	parent[node] = ++cnt;
	int ret = cnt;
	st.push(node);
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (parent[next] == 0) ret = min(ret, DFS(next));
		else if (id[next] == 0) ret = min(ret, parent[next]);
	}
	if (ret == parent[node]) {
		id_cnt++;
		vector <int> v;
		while (1) {
			int t = st.top();
			st.pop();
			id[t] = id_cnt;
			v.push_back(t);
			if (t == node) break;
		}
		SCC.push_back(v);
	}
	return ret;
}

int convert(int node) {
	if (node > 0) return node * 2 - 1;
	else return -node * 2;
}