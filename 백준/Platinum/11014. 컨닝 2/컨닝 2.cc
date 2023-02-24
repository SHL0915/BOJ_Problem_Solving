#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[6] = { -1,-1,-1,1,1,1 };
int dy[6] = { -1,0,1,-1,0,1 };

int N, M;
int arr[81][81];
vector <int> graph[7000];
int B[7000], mark[7000];

int convert(int x, int y);
int DFS(int node);

void solve() {
	memset(arr, 0, sizeof(arr));
	memset(B, -1, sizeof(B));
	int cnt = 0;
	for (int i = 0; i < 7000; i++) graph[i].clear();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '.') {
				arr[i][j] = 0;
				cnt++;
			}
			else arr[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j % 2 && arr[i][j] == 0) {
				for (int k = 0; k < 6; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					if (arr[ny][nx] == 1) continue;
					graph[convert(j, i)].push_back(convert(nx, ny));
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j % 2 && arr[i][j] == 0) {
				memset(mark, 0, sizeof(mark));
				ans += DFS(convert(j, i));
			}
		}
	}

	cout << cnt - ans << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

int convert(int x, int y) {
	return y * M + x;
}

int DFS(int node) {
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int now = graph[node][i];
		if (B[now] == -1 || mark[B[now]] == 0 && DFS(B[now])) {
			B[now] = node;
			return 1;
		}
	}
	return 0;
}