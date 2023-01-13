#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;

int T, N, M, K;
int graph[101][101];
int arr[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		memset(graph, INF, sizeof(graph));
		for (int i = 1; i <= N; i++) graph[i][i] = 0;
		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a][b] = c;
			graph[b][a] = c;
		}
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
		cin >> K;
		for (int i = 0; i < K; i++) cin >> arr[i];
		vector <pair<int, int>> cand;
		for (int i = 1; i <= N; i++) {
			int sum = 0;
			for (int j = 0; j < K; j++) sum += graph[i][arr[j]];
			cand.push_back({ sum, i });
		}
		sort(cand.begin(), cand.end());
		cout << cand[0].second << '\n';
	}
	return 0;
}