#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int M, N;
vector <int> arr[100001];
vector <int> table[100001];

int DP(int x, int y);

void solve() {
	while (1) {
		cin >> M >> N;
		if (M == 0 && N == 0) break;
		for (int i = 0; i < M; i++) {
			arr[i].clear();
			table[i].clear();
			arr[i].resize(N);
			table[i].resize(N, -1);
			for (int j = 0; j < N; j++) cin >> arr[i][j];
		}		
		cout << DP(0, 0) << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int DP(int x, int y) {
	if (x >= N || y >= M) return 0;
	int& ret = table[y][x];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, DP(x + 1, y));
	ret = max(ret, arr[y][x] + DP(x + 2, y));
	if (x == 0) ret = max(ret, DP(x, y + 1));
	ret = max(ret, arr[y][x] + DP(0, y + 2));
	return ret;
}