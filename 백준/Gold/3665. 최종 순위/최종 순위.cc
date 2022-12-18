#include <bits/stdc++.h>
using namespace std;

int t, N, M, flag;
int arr[501];
int graph[501][501];
int in_degree[501];
vector <int> ans;
queue <int> q;

void Topological();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> N;
		flag = 0;
		memset(graph, 0, sizeof(graph));
		memset(in_degree, 0, sizeof(in_degree));
		ans.clear();
		for (int i = 1; i <= N; i++) cin >> arr[i];
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				graph[arr[i]][arr[j]] = 1;
				in_degree[arr[j]] ++;
			}
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			int A, B;
			cin >> A >> B;
			if (graph[A][B] == 1) {
				graph[A][B] = 0;
				graph[B][A] = 1;
				in_degree[B] --;
				in_degree[A] ++;
			}
			else {
				graph[B][A] = 0;
				graph[A][B] = 1;
				in_degree[A] --;
				in_degree[B] ++;
			}
		}
		Topological();
		if (flag == 1) continue;
		else {
			for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
			cout << '\n';
		}
	}
	return 0;
}

void Topological() {
	while (q.size()) q.pop();
	for (int i = 1; i <= N; i++) if (in_degree[i] == 0) q.push(i);
	for (int i = 1; i <= N; i++) {
		if (q.size() > 2) {
			cout << "?\n";
			flag = 1;
			return;
		}
		else if (q.size() == 0) {
			cout << "IMPOSSIBLE\n";
			flag = 1;
			return;
		}
		int now = q.front();
		q.pop();
		ans.push_back(now);
		for (int j = 1; j <= N; j++) {
			if (graph[now][j] == 0) continue;
			int next = j;
			in_degree[next]--;
			if (in_degree[next] == 0) q.push(next);
		}
	}
}