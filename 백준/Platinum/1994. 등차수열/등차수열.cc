#include <bits/stdc++.h>
using namespace std;

int N, ans;
int arr[2001];
int table[2001][2001];

int DP(int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	if (N == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	memset(table, -1, sizeof(table));
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) ans = max(ans, DP(i, j));
	}
	cout << ans;
	return 0;
}

int DP(int left, int right) {
	if (left == right) return 1;
	int& ret = table[left][right];
	if (ret != -1) return ret;
	ret = 2;
	int diff = arr[right] - arr[left];
	int next = lower_bound(arr + right + 1, arr + N, arr[right] + diff) - arr;
	if (!(next == N || arr[next] != arr[right] + diff)) ret = max(ret, 1 + DP(right, next));
	return ret;
}