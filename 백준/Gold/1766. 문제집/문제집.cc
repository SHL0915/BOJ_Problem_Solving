#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
	bool operator() (int A, int B) {
		return A > B;
	}
};

int N, M;
int check[32001];
vector <int> graph[32001];
priority_queue <int, vector <int>, cmp> pq;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		check[B]++;
		graph[A].push_back(B);
	}
	for (int i = 1; i <= N; i++) if (check[i] == 0) pq.push(i);
	while (pq.size()) BFS();
	return 0;
}

void BFS() {
	int now = pq.top();
	pq.pop();
	check[now]--;
	if (check[now] <= 0) {
		cout << now << ' ';
		for (int i = 0; i < graph[now].size(); i++) pq.push(graph[now][i]);
	}
}