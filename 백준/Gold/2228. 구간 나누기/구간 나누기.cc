#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
long long arr[100];
long long table[100][100][2];

long long DP(int pos, int k, int state);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	memset(table, -1, sizeof(table));
	cout << DP(0, 0, 0);
	return 0;
}

long long DP(int pos, int k, int state) {
	if (k > M) return -INF;
	if (pos == N) {
		if (k == M) return 0;
		else return -INF;
	}
	long long& ret = table[pos][k][state];
	if (ret != -1) return ret;
	ret = -INF;
	if (state) ret = max(ret, arr[pos] + DP(pos + 1, k, 1));
	else ret = max(ret, arr[pos] + DP(pos + 1, k + 1, 1));
	ret = max(ret, DP(pos + 1, k, 0));
	return ret;
}