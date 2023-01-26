#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int arr[501];
int psum[501];
int table[501][501];

int DP(int left, int right);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	memset(table, -1, sizeof(table));
	cout << DP(1, N) << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

int DP(int left, int right) {
	if (left == right) return 0;
	int& ret = table[left][right];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = left; i < right; i++) ret = min(ret, DP(left, i) + DP(i + 1, right) + psum[right] - psum[left - 1]);
	return ret;
}