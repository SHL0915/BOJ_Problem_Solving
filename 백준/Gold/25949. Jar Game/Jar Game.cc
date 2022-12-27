#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int A, B, C;
int table[101][101][101][50];

int DP(int a, int b, int c, int turn);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> C;
	memset(table, -1, sizeof(table));
	int F = DP(A, B, C, 1);
	int S = (A + B + C) - F;
	if (F > S) cout << "F";
	else if (F == S) cout << "D";
	else cout << "S";
	return 0;
}

int DP(int a, int b, int c, int turn) {
	if (a == 0 && b == 0 && c == 0) return 0;
	int& ret = table[a][b][c][turn];
	if (ret != -1) return ret;
	int da = min(a, turn);
	int db = min(b, turn);
	int dc = min(c, turn);
	if (turn % 2) {
		ret = 0;
		if (a) ret = max(ret, da + DP(a - da, b, c, turn + 1));
		if (b) ret = max(ret, db + DP(a, b - db, c, turn + 1));
		if (c) ret = max(ret, dc + DP(a, b, c - dc, turn + 1));
	}
	else {
		ret = INF;
		if (a) ret = min(ret, DP(a - da, b, c, turn + 1));
		if (b) ret = min(ret, DP(a, b - db, c, turn + 1));
		if (c) ret = min(ret, DP(a, b, c - dc, turn + 1));
	}
	return ret;
}