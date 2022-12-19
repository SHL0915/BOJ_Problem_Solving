#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int t, N, M;
int arr[10];
int table[5001][5001];

int DP(int score, int cnt);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) cin >> arr[i];
		memset(table, -1, sizeof(table));
		int ans = DP(0, 0);
		if (ans == 0) cout << -1 << '\n';
		else cout << ans << '\n';		
	}
	return 0;
}

int DP(int score, int cnt) {
	if (cnt > N) return 0;
	if (cnt == N) return score;
	int &ret = table[score][cnt];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < M; i++) {
		ret = max(ret, DP(score + arr[i], cnt + score + arr[i]));
	}
	return ret;
}