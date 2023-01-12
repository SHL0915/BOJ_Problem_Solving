#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N;
string S;
int arr[1000001];
int table[1000001][2];

int DP(int pos, int mode);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'B') arr[i] = 1;
		else arr[i] = 0;
	}
	memset(table, -1, sizeof(table));
	cout << DP(N - 1, 0);
	return 0;
}

int DP(int pos, int mode) {
	if (pos == -1) return 0;
	int& ret = table[pos][mode];
	if (ret != -1) return ret;
	ret = INF;
	if (arr[pos] == mode) ret = min(ret, DP(pos - 1, mode));
	else {
		ret = min(ret, 1 + DP(pos - 1, mode));
		ret = min(ret, 1 + DP(pos - 1, mode ^ 1));
	}
	return ret;
}