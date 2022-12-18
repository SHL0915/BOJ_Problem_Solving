#include <bits/stdc++.h>
using namespace std;

int N , M;
vector <int> graph[32001];
int arr[32001];
queue <int> q;
vector <int> ans;

void Topological();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		arr[B] ++;
	}
	Topological();
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	return 0;
}

void Topological() {
	for (int i = 1; i <= N; i++) if (arr[i] == 0) q.push(i);
	for (int i = 1; i <= N; i++) {
		int now = q.front();
		ans.push_back(now);
		q.pop();
		for (int j = 0; j < graph[now].size(); j++) {
			int next = graph[now][j];
			arr[next]--;
			if (arr[next] == 0) q.push(next);
		}
	}
	return;
}