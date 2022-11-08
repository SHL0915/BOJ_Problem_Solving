#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, X, flag;
vector <int> graph[300001];
queue <pair<int, int>> q;
int mark[300001];

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K >> X;
	for (int i = 1; i <= N; i++) mark[i] = -1;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
	}
	q.push({ X,0 });
	while (q.size()) BFS();
	for (int i = 1; i <= N; i++) {
		if (mark[i] == K) {
			flag = 1;
			cout << i << '\n';
		}
	}
	if (flag == 0) cout << -1;
	return 0;
}

void BFS() {
	pair<int, int> temp = q.front();
	q.pop();
	int vertex = temp.first;
	int d = temp.second;
	if (mark[vertex] != -1) return;
	mark[vertex] = d;
	for (int i = 0; i < graph[vertex].size(); i++) q.push({ graph[vertex][i], d + 1 });
	return;
}