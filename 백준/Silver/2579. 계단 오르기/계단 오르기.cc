#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int arr[301];
int table[301][3][2];

int DP(int pos, int step, int jump);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	memset(table, -1, sizeof(table));
	cout << DP(0, 0, 0);
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

int DP(int pos, int step, int jump) {
	if (pos == N - 1) {
		if (step == 2) return -INF;
		else return arr[N - 1];
	}
	int& ret = table[pos][step][jump];
	if (ret != -1) return ret;
	ret = 0;
	if (step < 2) ret = max(ret, arr[pos] + DP(pos + 1, step + 1, 0));
	if (jump == 0) ret = max(ret, DP(pos + 1, 0, 1));
	return ret;
}