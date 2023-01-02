#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

string S;
int N;
int pal[2501][2501];
int table[2501];

int DP(int pos);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	N = S.length();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j + i >= N) break;
			if (S[j] == S[j + i]) {
				if (i <= 1) pal[j][j + i] = 1;
				else if (pal[j + 1][j + i - 1]) pal[j][j + i] = 1;
			}
		}
	}
	memset(table, -1, sizeof(table));	
	cout << DP(0);
	return 0;
}

int DP(int pos) {
	if (pos == N) return 0;
	int& ret = table[pos];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = pos; i < N; i++) if (pal[pos][i]) ret = min(ret, 1 + DP(i + 1));
	return ret;
}