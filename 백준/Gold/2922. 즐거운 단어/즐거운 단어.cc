#include <bits/stdc++.h>
using namespace std;

string S;
long long table[101][5][5][2];

long long DP(int pos, int v, int c, int l);
bool check(char c);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	memset(table, -1, sizeof(table));
	cout << DP(0, 0, 0, 0);
	return 0;
}

long long DP(int pos, int v, int c, int l) {
	if (pos == S.length()) return (v < 3 && c < 3 && l == 1);
	if (v >= 3 || c >= 3) return 0;
	long long& ret = table[pos][v][c][l];
	if (ret != -1) return ret;
	ret = 0;
	if (S[pos] == '_') {
		if (l) {
			ret += 5 * DP(pos + 1, v + 1, 0, l);
			ret += 21 * DP(pos + 1, 0, c + 1, l);
		}
		else {
			ret += 5 * DP(pos + 1, v + 1, 0, l);
			ret += 20 * DP(pos + 1, 0, c + 1, l);
			ret += DP(pos + 1, 0, c + 1, l + 1);
		}
	}
	else {
		if (S[pos] == 'L') ret += DP(pos + 1, 0, c + 1, 1);
		else if (check(S[pos])) ret += DP(pos + 1, v + 1, 0, l);
		else ret += DP(pos + 1, 0, c + 1, l);
	}
	return ret;
}

bool check(char c) {
	switch (c) {
	case 'A': return true;
	case 'E': return true;
	case 'I': return true;
	case 'O': return true;
	case 'U': return true;
	}
	return false;
}