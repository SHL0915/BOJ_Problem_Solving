#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, ans;
int arr[17];
int table[17][161];

int DP(vector<int>& v, int pos, int h);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < (1 << N); i++) {
		vector <int> A, B;
		int bit = 1;
		int idx = 0;
		while (bit <= (1 << N) - 1) {
			if (bit & i) A.push_back(arr[idx]);
			else B.push_back(arr[idx]);
			idx++;
			bit <<= 1;
		}
		int a, b;
		memset(table, -1, sizeof(table));
		a = DP(A, A.size() - 1, 0);
		memset(table, -1, sizeof(table));
		b = DP(B, B.size() - 1, 0);
		a = max(a, 0);
		b = max(b, 0);
		ans = max(ans, a * b);
	}
	if (ans) cout << ans;
	else cout << -1;
	return 0;
}

int DP(vector<int>& v, int pos, int h) {
	if (h > 160 || h < 0) return -INF;
	if (pos == -1) {
		if (h) return -INF;
		else return 0;
	}
	int& ret = table[pos][h];
	if (ret != -1) return ret;
	ret = -INF;
	ret = max(ret, DP(v, pos - 1, h));
	ret = max(ret, v[pos] + DP(v, pos - 1, h - v[pos]));
	ret = max(ret, DP(v, pos - 1, h + v[pos]));
	ret = max(ret, h + DP(v, pos - 1, v[pos] - h));
	return ret;
}