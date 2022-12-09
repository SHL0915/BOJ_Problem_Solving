#include <bits/stdc++.h>
using namespace std;

string S;
int cnt[3];
bool table[51][51][51][3][3] = {false, };
char ans[51];

bool DP(int A, int B, int C, int p, int pp);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'A') cnt[0] ++;
		else if (S[i] == 'B') cnt[1] ++;
		else cnt[2] ++;
	}
	if (DP(0, 0, 0, -1, -1)) {
		for (int i = 0; i < S.length(); i++) cout << ans[i];
	}
	else cout << -1;
	return 0;
}

bool DP(int A, int B, int C, int p, int pp) {
	if (A == cnt[0] && B == cnt[1] && C == cnt[2]) return true;
	if (table[A][B][C][p][pp]) return false;
	table[A][B][C][p][pp] = true;
	if (A + 1 <= cnt[0]) {
		ans[A + B + C] = 'A';
		if (DP(A + 1, B, C, pp, 0)) return true;
	}
	if (B + 1 <= cnt[1]) {
		ans[A + B + C] = 'B';
		if (pp != 1) {
			if (DP(A, B + 1, C, pp, 1)) return true;
		}
	}
	if (C + 1 <= cnt[2]) {
		ans[A + B + C] = 'C';
		if (pp != 2 && p != 2) {
			if (DP(A, B, C + 1, pp, 2)) return true;
		}
	}
	return false;
}