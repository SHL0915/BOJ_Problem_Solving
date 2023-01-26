#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[1001];
int table[1001][1001];

int DP(int pos, int size);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	memset(table, -1, sizeof(table));
	cout << DP(0, 0);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int DP(int pos, int size) {
	if (pos == N) return 0;
	int& ret = table[pos][size];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, DP(pos + 1, size));
	if (arr[pos] > size) ret = max(ret, 1 + DP(pos + 1, arr[pos]));
	return ret;
}