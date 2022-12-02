#include <bits/stdc++.h>
using namespace std;
typedef __int128 lli;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

long long N, A, B, C, D, ans, cnt;
long long cost[10001];
int visited[10001];
long long dist[10001];

long long weight(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> A >> B >> C >> D;
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		dist[i] = INF;
	}
	dist[0] = 0;
	for (int i = 0; i < N; i++) {
		int now = -1;
		long long min_dist = INF;
		for (int j = 0; j < N; j++) {
			if (visited[j] == 0 && min_dist > dist[j]) {
				min_dist = dist[j];
				now = j;
			}
		}
		ans += dist[now];
		visited[now] = 1;
		for (int j = 0; j < N; j++) {
			if (visited[j] == 1) continue;
			dist[j] = min(dist[j], weight(now, j));
		}
	}
	cout << ans;
	return 0;
}

long long weight(int x, int y) {
	if (y < x) {
		int temp = x;
		x = y;
		y = temp;
	}
	long long ret = (((lli)cost[x] * A + (lli)cost[y] * B) % C) ^ D;
	return ret;
}