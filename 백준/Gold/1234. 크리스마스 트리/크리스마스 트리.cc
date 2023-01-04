#include <bits/stdc++.h>
using namespace std;

int N, R, G, B, sum;
long long fact[11];
long long table[11][101][101];

void factorial();
long long DP(int pos, int r, int g);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> R >> G >> B;
	sum = R + G + B;
	memset(table, -1, sizeof(table));
	factorial();
	cout << DP(1, R, G);
	return 0;
}

void factorial() {
	fact[0] = 1;
	for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i;
	return;
}

long long DP(int pos, int r, int g) {
	if (pos == N + 1) return 1;
	long long& ret = table[pos][r][g];
	if (ret != -1) return ret;
	int b = sum - (pos * (pos - 1) / 2 + r + g);
	ret = 0;
	if (r >= pos) ret += DP(pos + 1, r - pos, g);
	if (g >= pos) ret += DP(pos + 1, r, g - pos);
	if (b >= pos) ret += DP(pos + 1, r, g);
	if (pos % 2 == 0) {
		if (r >= pos / 2 && g >= pos / 2) ret += DP(pos + 1, r - pos / 2, g - pos / 2) * (fact[pos] / (fact[pos / 2] * fact[pos / 2]));
		if (r >= pos / 2 && b >= pos / 2) ret += DP(pos + 1, r - pos / 2, g) * (fact[pos] / (fact[pos / 2] * fact[pos / 2]));
		if (g >= pos / 2 && b >= pos / 2) ret += DP(pos + 1, r, g - pos / 2) * (fact[pos] / (fact[pos / 2] * fact[pos / 2]));
	}
	if (pos % 3 == 0 && r >= pos / 3 && g >= pos / 3 && b >= pos / 3) ret += DP(pos + 1, r - pos / 3, g - pos / 3) * (fact[pos] / (fact[pos / 3] * fact[pos / 3] * fact[pos / 3]));
	return ret;
}