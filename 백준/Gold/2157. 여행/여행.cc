#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M, K;
long long graph[301][301];
long long table[301][301];

long long DP(int pos, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	memset(graph, -INF, sizeof(graph));
	for (int i = 0; i < K; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = max(graph[a][b], c);
	}
	memset(table, -1, sizeof(table));
	cout << DP(1, 1);
	return 0;
}

long long DP(int pos, int k) {
	if (k > M) return -INF;
	if (pos == N) return 0;
	long long& ret = table[pos][k];
	if (ret != -1) return ret;
	ret = -INF;
	for (int i = pos + 1; i <= N; i++) {
		if (graph[pos][i] == -INF) continue;
		ret = max(ret, graph[pos][i] + DP(i, k + 1));
	}
	return ret;
}