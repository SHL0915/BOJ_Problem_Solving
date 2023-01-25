#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[10001];
vector <int> graph[10001], v;
int table[10001][2];
vector <pii> ans[10001][2];

int DP(int node, int mode, int par);
void DFS(int node, int mode);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	memset(table, -1, sizeof(table));
	int a = DP(1, 0, -1);
	int b = DP(1, 1, -1);
	if (a > b) {
		cout << a << '\n';
		DFS(1, 0);
	}
	else {
		cout << b << '\n';
		int node = 1, mode = 1;
		DFS(1, 1);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
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

int DP(int node, int mode, int par) {
	int& ret = table[node][mode];
	if (ret != -1) return ret;	
	if (mode) {
		ret = arr[node];
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i];
			if (next == par) continue;
			ret += DP(next, 0, node);
			ans[node][mode].push_back({ next,0 });
		}
	}
	else {
		ret = 0;
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i];
			if (next == par) continue;
			if (DP(next, 0, node) > DP(next, 1, node)) {
				ret += DP(next, 0, node);
				ans[node][mode].push_back({ next,0 });
			}
			else {
				ret += DP(next, 1, node);
				ans[node][mode].push_back({ next,1 });
			}			
		}
	}
	return ret;
}

void DFS(int node, int mode) {
	if (mode == 1) v.push_back(node);
	for (int i = 0; i < ans[node][mode].size(); i++) {
		DFS(ans[node][mode][i].first, ans[node][mode][i].second);
	}
	return;
}