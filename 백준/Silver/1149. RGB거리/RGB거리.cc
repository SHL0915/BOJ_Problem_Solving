#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int arr[1001][3];
int table[1001][3];

int DP(int pos, int color);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	memset(table, -1, sizeof(table));
	cout << min({ DP(1,0) + arr[0][0], DP(1,1) + arr[0][1], DP(1,2) + arr[0][2] });
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int DP(int pos, int color) {
	if (pos == N) return 0;
	int& ret = table[pos][color];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i < 3; i++) {
		if (i == color) continue;
		ret = min(ret, arr[pos][i] + DP(pos + 1, i));
	}
	return ret;
}