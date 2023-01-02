#include <bits/stdc++.h>
using namespace std;

int T, W;
int arr[1001];
long long table[1001][31][3];

long long DP(int t, int w, int pos);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T >> W;
	for (int i = 1; i <= T; i++) cin >> arr[i];
	memset(table, -1, sizeof(table));
	cout << DP(0, 0, 1);
	return 0;
}

long long DP(int t, int w, int pos) {
	if (t > T || w > W) return 0;
	long long& ret = table[t][w][pos];
	if (ret != -1) return ret;
	ret = (arr[t] == pos);
	if (pos == 1) ret = max(DP(t + 1, w, 1), DP(t + 1, w + 1, 2)) + (arr[t] == pos);
	else ret = max(DP(t + 1, w, 2), DP(t + 1, w + 1, 1)) + (arr[t] == pos);
	return ret;
}