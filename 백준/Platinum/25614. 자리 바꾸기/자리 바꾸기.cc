#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string M;
vector <int> graph[200005];
int arr[200005];
int parent[200005], sz[200005], mark[200005];
int table[200005][21];
int modTable[200005];

void Union(int a, int b);
int Find(int a);
void DFS(int node);
void cal(int mod);
int f(int node, int k);

void solve() {
	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		graph[i].push_back(arr[i]);
		table[i][0] = arr[i];
	}

	for (int i = 1; i <= N; i++) if (mark[i] == 0) DFS(i);

	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= N; j++) table[j][i] = table[table[j][i - 1]][i - 1];
	}

	memset(modTable, -1, sizeof(modTable));
	for (int i = 1; i <= N; i++) {
		int now = sz[Find(i)];
		if (modTable[now] == -1) cal(now);
		cout << f(i, modTable[now]) << " ";
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

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) {
		parent[a] = b;
		sz[b] += sz[a];
	}
	else {
		parent[b] = a;
		sz[a] += sz[b];
	}
	return;
}

int Find(int a) {
	if (a == parent[a]) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void DFS(int node) {
	if (mark[node]) return;
	mark[node] = 1;

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		Union(node, next);
		DFS(next);
	}
	return;
}

void cal(int mod) {
	ll ret = 0;
	for (int i = 0; i < M.length(); i++) {
		ret *= 10;
		ret += M[i] - '0';
		ret %= mod;
	}
	modTable[mod] = ret;
	return;
}

int f(int node, int k) {
	int idx = 0;
	while (k) {
		if (k & 1) node = table[node][idx];
		k /= 2;
		idx++;
	}
	return node;
}