#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, max_length = 0, cnt;
vector <int> graph[20001];
int mark[20001];
queue <pair <int, int>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) mark[i] = -1;
	q.push({ 1,0 });
	while (q.size()) BFS();
	for (int i = 1; i <= N; i++) max_length = max(max_length, mark[i]);
	int flag = 0;
	for (int i = 1; i <= N; i++) {
		if (mark[i] == max_length) {
			cnt++;
			if (flag == 0) cout << i << " ";
			flag = 1;
		}
	}
	cout << max_length << " " << cnt;
	return 0;
}

void BFS() {
	pair <int, int> temp = q.front();
	q.pop();
	if (mark[temp.first] != -1) return;
	mark[temp.first] = temp.second;
	for (int i = 0; i < graph[temp.first].size(); i++) q.push({ graph[temp.first][i], temp.second + 1 });
	return;
}