#include <bits/stdc++.h>
using namespace std;

int N, M, ans, flag;
int arr[305];
int table[305][305][2];

int DP(int left, int right, int pos, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] == 0) flag = 1;
	}
	if (flag == 0) N++;
	sort(arr, arr + N);
	int start = lower_bound(arr, arr + N, 0) - arr;
	for (int i = 0; i <= N; i++) {
		memset(table, -1, sizeof(table));
		ans = max(ans, DP(start, start, 0, i));
	}
	if (flag) ans += M;
	cout << ans;
	return 0;
}

int DP(int left, int right, int pos, int k) {
	if (!k) return 0;
	if (left == 0 && right == N - 1) return 0;
	int& ret = table[left][right][pos];
	if (ret != -1) return ret;
	int now = pos ? arr[right] : arr[left];
	ret = 0;
	if (left > 0) {
		int d = now - arr[left - 1];
		ret = max(ret, DP(left - 1, right, 0, k - 1) + M - k * d);
	}
	if (right < N - 1) {
		int d = arr[right + 1] - now;
		ret = max(ret, DP(left, right + 1, 1, k - 1) + M - k * d);
	}
	return ret;
}