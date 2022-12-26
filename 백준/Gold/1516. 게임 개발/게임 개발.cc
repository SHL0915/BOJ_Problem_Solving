#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> graph[501];
int in_degree[501];
queue <int> q;
int table[501];
int arr[501];

void Topological();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		while (1) {
			int A;
			cin >> A;
			if (A == -1) break;
			graph[A].push_back(i);
			in_degree[i] ++;
		}
	}
	Topological();
	for (int i = 1; i <= N; i++) cout << table[i] << '\n';
	return 0;
}

void Topological() {
	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
			table[i] += arr[i];
		}
	}
	for (int i = 0; i < N; i++) {
		int now = q.front();
		q.pop();
		for (int j = 0; j < graph[now].size(); j++) {
			int next = graph[now][j];
			table[next] = max(table[next], table[now] + arr[next]);
			if (--in_degree[next] == 0) q.push(next);
		}
	}
}