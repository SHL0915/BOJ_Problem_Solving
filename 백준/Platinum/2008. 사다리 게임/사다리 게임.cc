#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M, a, b, X, Y;
int arr[501];
long long table[505][105];

long long DP(int pos, int now);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	cin >> a >> b >> X >> Y;
	for (int i = 0; i < M; i++) cin >> arr[i];
	arr[M] = -1;
	memset(table, -1, sizeof(table));
	cout << DP(0, a);
	return 0;
}

long long DP(int pos, int now) {
	if (pos == M + 1) {
		if (now == b) return 0;
		else return INF;
	}
	long long& ret = table[pos][now];
	if (ret != -1) return ret;
	ret = INF;
	if (arr[pos] != now && arr[pos] != now - 1) ret = min(ret, DP(pos + 1, now));
	if (arr[pos] == now || arr[pos] == now - 1) {
		if (arr[pos] == now) ret = min(ret, DP(pos + 1, now + 1));
		if (arr[pos] == now - 1) ret = min(ret, DP(pos + 1, now - 1));
		ret = min(ret, X + DP(pos + 1, now));
	}
	if (now > 1) ret = min(ret, Y + DP(pos, now - 1));
	if (now < N) ret = min(ret, Y + DP(pos, now + 1));
	return ret;
}