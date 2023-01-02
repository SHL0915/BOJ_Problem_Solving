#include <bits/stdc++.h>
using namespace std;

int N, ans;
vector <int> graph[10001];
int arr[10001];
int table[10001];
int in_degree[10001];
queue <int> q;

void Topology();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i] >> in_degree[i];
		for (int j = 0; j < in_degree[i]; j++) {
			int a;
			cin >> a;
			graph[a].push_back(i);
		}
	}
	Topology();
	cout << ans;
	return 0;
}

void Topology() {
	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) {
			table[i] = arr[i];
			ans = max(ans, table[i]);
			q.push(i);
		}
	}
	for (int i = 0; i < N; i++) {
		int now = q.front();
		q.pop();
		for (int j = 0; j < graph[now].size(); j++) {
			int next = graph[now][j];
			table[next] = max(table[next], table[now] + arr[next]);
			ans = max(ans, table[next]);
			if (--in_degree[graph[now][j]] == 0) q.push(graph[now][j]);
		}
 	}
	return;
}