#include <bits/stdc++.h>
using namespace std;

int N, ans;
int cost[10001];
vector <int> tree[10001];
int table[10001][2];
vector <int> path[10001][2];

int DFS(int node, int par, int state);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	memset(table, -1, sizeof(table));
	for (int i = 1; i <= N; i++) cin >> cost[i];
	for (int i = 0; i < N - 1; i++) {
		int A, B;
		cin >> A >> B;
		tree[A].push_back(B);
		tree[B].push_back(A);
	}
	int A = DFS(1, 0, 0);
	int B = DFS(1, 0, 1);
	if (A > B) {
		ans = A;
		for (int j = 0; j < path[1][0].size(); j++) path[0][0].push_back(path[1][0][j]);
	}
	else {
		ans = B;
		for (int j = 0; j < path[1][1].size(); j++) path[0][0].push_back(path[1][1][j]);
	}
	sort(path[0][0].begin(), path[0][0].end());
	path[0][0].erase(unique(path[0][0].begin(), path[0][0].end()), path[0][0].end());
	cout << ans << '\n';
	for (int i = 0; i < path[0][0].size(); i++) cout << path[0][0][i] << " ";
	return 0;
}

int DFS(int node, int par, int state) {
	if (table[node][state] != -1) return table[node][state];
	if (state == 0) {
		table[node][state] = 0;
		for (int i = 0; i < tree[node].size(); i++) {
			if (tree[node][i] == par) continue;
			int A = DFS(tree[node][i], node, 0);
			int B = DFS(tree[node][i], node, 1);
			if (A > B) {
				table[node][state] += A;
				for (int j = 0; j < path[tree[node][i]][0].size(); j++) path[node][state].push_back(path[tree[node][i]][0][j]);
			}
			else {
				table[node][state] += B;
				for (int j = 0; j < path[tree[node][i]][1].size(); j++) path[node][state].push_back(path[tree[node][i]][1][j]);
			}			
		}
	}
	else {
		table[node][state] = cost[node];
		path[node][state].push_back(node);
		for (int i = 0; i < tree[node].size(); i++) {
			if (tree[node][i] == par) continue;
			table[node][state] += DFS(tree[node][i], node, 0);
			for (int j = 0; j < path[tree[node][i]][0].size(); j++) path[node][state].push_back(path[tree[node][i]][0][j]);			
		}
	}	
	return table[node][state];
}