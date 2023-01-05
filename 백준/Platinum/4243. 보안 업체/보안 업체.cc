#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int T, N, a;
int arr[101];
long long table[101][101][2];

long long DP(int left, int right, int pos);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> a;
		for (int i = 2; i <= N; i++) {
			cin >> arr[i];
			arr[i] += arr[i - 1];
		}
		memset(table, -1, sizeof(table));
		cout << DP(a, a, 0) << '\n';
	}
	return 0;
}

long long DP(int left, int right, int pos) {
	if (left == 1 && right == N) return 0;
	long long& ret = table[left][right][pos];
	if (ret != -1) return ret;
	ret = INF;
	int now = (pos == 0) ? arr[left] : arr[right];
	long long k = N - (right - left + 1);
	if (left > 1) ret = min(ret, k * (now - arr[left - 1]) + DP(left - 1, right, 0));
	if (right < N) ret = min(ret, k * (arr[right + 1] - now) + DP(left, right + 1, 1));
	return ret;
}