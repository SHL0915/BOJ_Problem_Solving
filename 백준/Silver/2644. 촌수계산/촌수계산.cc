#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, A, B;
vector <int> graph[100];
int mark[100];
queue <pair<int, int>> q;

void BFS(int toward);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> A >> B;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}	
	q.push({ A - 1,1 });
	while (q.size()) BFS(B - 1);
	q.push({ B - 1,1 });
	while (q.size()) BFS(A - 1);
	cout << -1;
	return 0;
}

void BFS(int toward) {
	pair <int, int> temp = q.front();
	q.pop();
	if (mark[temp.first] != 0) return;
	mark[temp.first] = temp.second;
	if (temp.first == toward) {
		cout << temp.second - 1;
		exit(0);
	}
	for (int i = 0; i < graph[temp.first].size(); i++) q.push({ graph[temp.first][i],temp.second + 1 });	
	return;
}