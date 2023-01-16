#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, B, ans = INF;
int arr[501][501];
int val[257];

void solve() {
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}
	memset(val, INF, sizeof(val));
	for (int i = 256; i >= 0; i--) {
		int sum = 0, remove = 0, put = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[j][k] > i) remove += (arr[j][k] - i);
				else put += (i - arr[j][k]);
				sum += (arr[j][k] - i);
			}
		}
		if (sum + B < 0) continue;
		else {
			ans = min(ans, remove * 2 + put);
			val[i] = remove * 2 + put;
		}
	}
	cout << ans << " ";
	for (int i = 256; i >= 0; i--) {
		if (val[i] == ans) {
			cout << i;
			return;
		}
	}
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