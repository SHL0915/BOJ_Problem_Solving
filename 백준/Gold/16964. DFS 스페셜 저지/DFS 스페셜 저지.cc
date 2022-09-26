#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, u, v, k;
vector<int> graph[100000];
int mark[100000] = { 0 };
int order[100000];
int judge[100000];

bool cmp(int A, int B) {
	return order[A] < order[B];
}

void DFS(int vertex);

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
	k = 1;
	if (judge[0] == 1)
		DFS(0);
	cout << 0;
	return 0;
}

void DFS(int vertex) {
	if (k == N) {
		cout << 1;
		exit(0);
	}
	if (mark[vertex] != 0)
		return;
	mark[vertex] = 1;
	for (int i = 0; i < graph[vertex].size(); i++) {
		if (graph[vertex][i] == judge[k] - 1) {
			k++;
			DFS(graph[vertex][i]);
		}
	}
}