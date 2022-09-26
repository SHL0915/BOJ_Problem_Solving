#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, u, v, k;
vector<int> graph[100000];
queue<int> q;
int mark[100000] = { 0 };
int judge[100000];
int order[100000];

bool cmp(int A, int B) {
	return order[A] < order[B];
}

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}
	for (int i = 0; i < N; i++) {
		cin >> judge[i];
		order[judge[i] - 1] = i;
	}
	for (int i = 0; i < N; i++) 
		stable_sort(graph[i].begin(), graph[i].end(), cmp);
	if (judge[0] == 1) {
		k = 0;
		q.push(0);
		while(q.size())
			BFS();
	}
	cout << 0;
	return 0;
}

void BFS() {	
	int vertex = q.front();
	q.pop();
	if (mark[vertex] != 0)
		return;
	if (vertex == judge[k] - 1)
		k++;
	else {
		cout << 0;
		exit(0);
	}
	if (k == N) {
		cout << 1;
		exit(0);
	}
	mark[vertex] = 1;
	for (int i = 0; i < graph[vertex].size(); i++) {	
		q.push(graph[vertex][i]);
	}
}