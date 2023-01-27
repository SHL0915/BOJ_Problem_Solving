#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int mod = 1000000007;

ll N, K, ans;
vector <int> graph[51];
ll table[51][51];

void DFS(int node, int par);

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(1, -1);
	for (int i = 1; i <= N; i++) ans = (ans + table[i][K]) % mod;
	cout << ans;
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

void DFS(int node, int par) {
	ll arr[51][51] = { 0 }, cnt = 0;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (next == par) continue;
		DFS(next, node);
		if (cnt++ == 0) {
			for (int i = 1; i <= K; i++) arr[cnt][i] = table[next][i - 1];
		}
		else {
			for (int i = 0; i <= K; i++) {
				arr[cnt][i] = arr[cnt - 1][i];
				for (int j = 1; j < i; j++) {
					arr[cnt][i] += (arr[cnt - 1][j] * table[next][i - j]);
					arr[cnt][i] %= mod;
				}
			}
		}
	}
	for (int i = 2; i <= K; i++) table[node][i] = arr[cnt][i];
	table[node][0] = 1;
	table[node][1] = 1;
	return;
}