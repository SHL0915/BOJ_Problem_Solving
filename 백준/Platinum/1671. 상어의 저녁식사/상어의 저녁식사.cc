#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector <int> graph[101];
pair <int, pii> arr[51];
int A[101], B[101], mark[101];

int DFS(int node);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (arr[i].first >= arr[j].first && arr[i].second.first >= arr[j].second.first && arr[i].second.second >= arr[j].second.second) {
				if (arr[i].first == arr[j].first && arr[i].second.first == arr[j].second.first && arr[i].second.second == arr[j].second.second) {
					if (i < j) continue;
				}
				graph[i * 2 - 1].push_back(j);
				graph[i * 2].push_back(j);
			}
		}
	}
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int cnt = 0;
	for (int i = 1; i <= 2 * N; i++) {
		if (A[i] == -1) {
			memset(mark, 0, sizeof(mark));
			cnt += DFS(i);
		}
	}
	cout << N - cnt;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int DFS(int node) {
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int now = graph[node][i];
		if (B[now] == -1 || mark[B[now]] == 0 && DFS(B[now])) {
			B[now] = node;
			A[node] = now;
			return 1;
		}
	}
	return 0;
}