#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, T, ans;
pair<int, int> arr[101];
int table[101][10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> T;
	for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= T; j++) {
			table[i][j] = max(table[i][j], table[i - 1][j]);
			if (arr[i].first <= j) table[i][j] = max(table[i][j], table[i - 1][j - arr[i].first] + arr[i].second);
			ans = max(ans, table[i][j]);
		}
	}
	cout << ans;
	return 0;
}