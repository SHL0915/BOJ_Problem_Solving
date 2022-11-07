#include <iostream>
#include <vector>
using namespace std;

int N, M, ans, idx;
vector <int> graph[10001];
int mark[10001];
int cnt[10001];

void DFS(int vertex, int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[B].push_back(A);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) mark[j] = 0;		
		DFS(i, i);
		ans = max(ans, cnt[i]);
	}
	for (int i = 1; i <= N; i++) if (cnt[i] == ans) cout << i << " ";
	return 0;
}

void DFS(int vertex, int start) {
	if (mark[vertex] != 0) return;
	mark[vertex] = 1;
	cnt[start]++;
	for (int i = 0; i < graph[vertex].size(); i++) DFS(graph[vertex][i], start);
	return;
}