#include <bits/stdc++.h>
using namespace std;

int N, K;
long long ans;
pair<int, int> arr[1001];
long long table[1001][10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= K; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			table[i][j] = max(table[i][j], table[i - 1][j]);
			if (arr[i].second > j) continue;
			table[i][j] = max(table[i][j], table[i - 1][j - arr[i].second] + arr[i].first);
			ans = max(ans, table[i][j]);
		}
	}
	cout << ans;
	return 0;
}