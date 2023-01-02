#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int N, K;
long long arr[5001];
long long table[5001][5001][2];

long long DP(int now, int k, int state);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	memset(table, -1, sizeof(table));
	cout << DP(0, 0, 0);
	return 0;
}

long long DP(int now, int k, int state) {
	if (k > K) return -INF;
	if (now == N) {
		if (k == K) return 0;
		else return -INF;
	}
	long long& ret = table[now][k][state];
	if (ret != -1) return ret;
	ret = -INF;
	if (state) ret = max(ret, arr[now] + DP(now + 1, k, 1));
	ret = max(ret, arr[now] + DP(now + 1, k + 1, 1));
	ret = max(ret, DP(now + 1, k, 0));
	return ret;
}