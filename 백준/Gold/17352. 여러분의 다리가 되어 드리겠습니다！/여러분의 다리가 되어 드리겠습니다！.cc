#include <iostream>
#include <vector>
using namespace std;

int N, s, e;
vector <int> graph[300001];
int mark[300001];

void DFS(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 2; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	DFS(1);
	for (int i = 1; i <= N; i++) {
		if (mark[i] == 0) s = i;
		else e = i;
	}
	cout << s << " " << e;
	return 0;
}

void DFS(int node) {
	if (mark[node] != 0) return;
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) DFS(graph[node][i]);
	return;
}