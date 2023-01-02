#include <bits/stdc++.h>
using namespace std;

string A, B, C;
int len;
int table[21][101][2];

int DP(int k, int now, int pos);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> C;
	len = B.length();
	memset(table, -1, sizeof(table));
	cout << DP(0, 0, 0) + DP(0, 0, 1);
	return 0;
}

int DP(int k, int now, int pos) {
	if (k == A.length()) return 1;
	int& ret = table[k][now][pos];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = now; i < len; i++) {
		if (pos && B[i] == A[k]) ret += DP(k + 1, i + 1, pos ^ 1);
		else if (pos == 0 && C[i] == A[k]) ret += DP(k + 1, i + 1, pos ^ 1);
	}
	return ret;
}