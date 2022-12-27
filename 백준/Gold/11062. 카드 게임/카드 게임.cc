#include <bits/stdc++.h>
using namespace std;

int t, N;
int arr[1000];
int table[1000][1000];

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
	if (turn) return ret = min(DP(left + 1, right, turn ^ 1), DP(left, right - 1, turn ^ 1));
	else return ret = max(arr[left] + DP(left + 1, right, turn ^ 1), arr[right] + DP(left, right - 1, turn ^ 1));
}