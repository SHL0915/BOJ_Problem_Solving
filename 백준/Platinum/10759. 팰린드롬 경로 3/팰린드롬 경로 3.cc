#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N;
int arr[505][505], A[505][505], B[505][505];
ll dp[505][505], temp[505][505];

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string S;
		cin >> S;
		for (int j = 1; j <= N; j++) arr[i][j] = S[j - 1];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			A[i][j] = arr[i][j];
			B[i][j] = arr[N + 1 - i][N + 1 - j];
		}
	}

	if (A[1][1] != B[1][1]) {
		cout << 0;
		return;
	}

	temp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		memset(dp, 0, sizeof(dp));	
		for (int j = 1; j < i; j++) {
			for (int k = 1; k < i; k++) {
				if (temp[j][k] == 0) continue;
				int a_x = j, a_y = i - j, b_x = k, b_y = i - k;
				if (A[a_y][a_x + 1] == B[b_y][b_x + 1]) dp[a_x + 1][b_x + 1] += temp[j][k], dp[a_x + 1][b_x + 1] %= mod;
				if (A[a_y][a_x + 1] == B[b_y + 1][b_x]) dp[a_x + 1][b_x] += temp[j][k], dp[a_x + 1][b_x] %= mod;
				if (A[a_y + 1][a_x] == B[b_y][b_x + 1]) dp[a_x][b_x + 1] += temp[j][k], dp[a_x][b_x + 1] %= mod;
				if (A[a_y + 1][a_x] == B[b_y + 1][b_x]) dp[a_x][b_x] += temp[j][k], dp[a_x][b_x] %= mod;
			}
		}
		swap(dp, temp);
	}

	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += temp[i][N + 1 - i], ans %= mod;
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