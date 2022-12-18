#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator() (int A, int B) {
		return A > B;
	}
};

int N, M;
vector <int> graph[32001];
int in_degree[32001];
priority_queue <int, vector<int>, cmp> pq;

void Topological();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		in_degree[B]++;
	}
	Topological();
	return 0;
}

void Topological() {
	for (int i = 1; i <= N; i++) if (in_degree[i] == 0) pq.push(i);
	for (int i = 1; i <= N; i++) {
		int now = pq.top();
		pq.pop();
		cout << now << " ";
		for (int j = 0; j < graph[now].size(); j++) {
			int next = graph[now][j];
			in_degree[next]--;
			if (in_degree[next] == 0) pq.push(next);
		}
	}
}