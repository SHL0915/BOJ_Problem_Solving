#include <bits/stdc++.h>
using namespace std;

int t, N;
int arr[1001];
int table[1001][1001];

int DP(int left, int right, int turn);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> arr[i];
		memset(table, -1, sizeof(table));
		cout << DP(0, N - 1, 0) << '\n';
	}
	return 0;
}

int DP(int left, int right, int turn) {
	if (left > right) return 0;
	int& ret = table[left][right];
	if (ret != -1) return ret;
	if (turn) ret = min(DP(left + 1, right, turn ^ 1), DP(left, right - 1, turn ^ 1));
	else ret = max(arr[left] + DP(left + 1, right, turn ^ 1), arr[right] + DP(left, right - 1, turn ^ 1));
	return ret;
}