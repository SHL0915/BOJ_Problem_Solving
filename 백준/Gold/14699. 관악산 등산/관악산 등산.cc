#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
int height[5001];
vector <int> graph[5001];
int table[5001];

int DFS(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> height[i];
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	for (int i = 1; i <= N; i++) cout << DFS(i) << '\n';
	return 0;
}

int DFS(int node) {
	if (table[node] != 0) return table[node];
	table[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		if (height[node] < height[graph[node][i]]) table[node] = max(table[node], 1 + DFS(graph[node][i]));
	}
	return table[node];
}