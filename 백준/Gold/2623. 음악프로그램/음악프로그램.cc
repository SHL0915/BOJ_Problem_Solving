#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, pre, now;
vector <int> graph[1001];
int check[1001];
queue <int> q;
vector <int> turn;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> now;
			if (j != 0) {
				graph[pre].push_back(now);
				check[now]++;
			}
			pre = now;
		}
	}
	for (int i = 1; i <= N; i++) if (check[i] == 0) q.push(i);
	while (q.size()) BFS();
	if (turn.size() != N) cout << 0;
	else for (int i = 0; i < turn.size(); i++) cout << turn[i] << '\n';	
	return 0;
}

void BFS() {
	int now = q.front();
	q.pop();
	check[now]--;
	if (check[now] <= 0) {
		turn.push_back(now);
		for (int i = 0; i < graph[now].size(); i++) q.push(graph[now][i]);
	}
}