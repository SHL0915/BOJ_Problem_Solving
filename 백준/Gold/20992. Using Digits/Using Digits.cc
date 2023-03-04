#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
string key;
int arr[101][101];
int table[101][101][51];

int DP(int x, int y, int pos);

void solve() {
	cin >> M >> N;
	cin >> key;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) arr[i][j] = s[j] - '0';
	}

	memset(table, -1, sizeof(table));
	cout << DP(0, N - 1, 0);
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

int DP(int x, int y, int pos) {
	if (x >= M || y < 0) return INF;
	if (x == M - 1 && y == 0) return arr[y][x];
	int& ret = table[x][y][pos];
	if (ret != -1) return ret;
	ret = INF;
	int hop = key[pos] - '0' + 1;
	ret = min(ret, arr[y][x] + DP(x + 1, y, pos));
	ret = min(ret, arr[y][x] + DP(x, y - 1, pos));
	if (pos < key.length()) {
		ret = min(ret, arr[y][x] + DP(x + hop, y, pos + 1));
		ret = min(ret, arr[y][x] + DP(x, y - hop, pos + 1));
	}
	return ret;
}