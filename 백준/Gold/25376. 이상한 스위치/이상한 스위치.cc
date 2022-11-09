#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, S, E, C;
vector <int> graph[21];
int mark[(1 << 20)];
queue <pair <int, int>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < (1 << N); i++) mark[i] = -1;
	int bit = 1;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		if (A == 1) S |= bit;
		bit <<= 1;
	}
	E = (1 << N) - 1;
	for (int i = 1; i <= N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			int v;
			cin >> v;
			graph[i].push_back(v);
		}
	}
	q.push({ S,0 });
	while (q.size()) BFS();
	cout << mark[E];
	return 0;
}

void BFS() {
	pair <int, int> f = q.front();
	q.pop();
	int now = f.first;
	int d = f.second;
	if (mark[now] != -1) return;
	mark[now] = d;
	for (int i = 1; i <= N; i++) {
		if (now & (1 << (i - 1))) continue;
		int input = now;
		input ^= 1 << (i - 1);
		for (int j = 0; j < graph[i].size(); j++) input ^= 1 << (graph[i][j] - 1);
		q.push({ input, d + 1 });
	}
	return;
}