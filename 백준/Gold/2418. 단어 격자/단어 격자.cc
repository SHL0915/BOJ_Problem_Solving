#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };

int H, W, L;
string S;
char arr[201][201];
ll table[101][201][201];

ll DP(int pos, int x, int y);

void solve() {
	cin >> H >> W >> L;
	for (int i = 0; i < H; i++) {
		string s; cin >> s;
		for (int j = 0; j < W; j++) arr[i][j] = s[j];
	}

	cin >> S;

	memset(table, -1, sizeof(table));
	
	ll ans = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (arr[i][j] == S[0]) ans += DP(0, j, i);			
		}
	}

	cout << ans;
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

ll DP(int pos, int x, int y) {
	if (pos == L - 1) return 1;
	ll& ret = table[pos][x][y];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
		if (arr[ny][nx] != S[pos + 1]) continue;
		ret += DP(pos + 1, nx, ny);
	}

	return ret;
}