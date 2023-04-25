#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M, sz;
vector <int> graph[1001][26];
int arr[201];
double table[205][1001];

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		graph[a][c - 'A'].push_back(b);
		graph[b][c - 'A'].push_back(a);
	}
	string s;
	cin >> s;
	sz = s.length();
	for (int i = 0; i < sz; i++) arr[i] = s[i] - 'A';

	table[0][1] = 1;
	double ans = 0;
	ans += table[0][N];
	for (int i = 0; i < sz; i++) {
		for (int j = 1; j < N; j++) {
			if (graph[j][arr[i]].size() == 0) table[i + 1][j] += table[i][j];
			else {
				double prob = 1.0 / graph[j][arr[i]].size();
				for (int k = 0; k < graph[j][arr[i]].size(); k++) {
					int next = graph[j][arr[i]][k];
					if (next == N) ans += table[i][j] * prob;
					table[i + 1][next] += table[i][j] * prob;
				}
			}
		}
	}

	cout << ans * 100;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(15);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}