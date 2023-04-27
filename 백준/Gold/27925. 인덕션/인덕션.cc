#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int arr[5005];
int table[5005][10][10][10];

int DP(int now, int a, int b, int c);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	memset(table, -1, sizeof(table));

	cout << DP(0, 0, 0, 0);
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

int DP(int now, int a, int b, int c) {
	if (now == N) return 0;
	int& ret = table[now][a][b][c];
	if (ret != -1) return ret;
	ret = INF;
	
	ret = min(ret, min({ abs(a - arr[now]), abs(10 + a - arr[now]), abs(10 + arr[now] - a) }) + DP(now + 1, arr[now], b, c));
	ret = min(ret, min({ abs(b - arr[now]), abs(10 + b - arr[now]), abs(10 + arr[now] - b) }) + DP(now + 1, a, arr[now], c));
	ret = min(ret, min({ abs(c - arr[now]), abs(10 + c - arr[now]), abs(10 + arr[now] - c) }) + DP(now + 1, a, b, arr[now]));

	return ret;
}