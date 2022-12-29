#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000000;

int N;
long long ans;
long long table[1 << 11][10][100];

long long DP(int state, int num, int pos);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	memset(table, -1, sizeof(table));
	for (int i = 1; i < 10; i++) ans = (ans + DP((1 << i), i, 1)) % mod;
	cout << ans << '\n';
	return 0;
}

long long DP(int state, int num, int pos) {
	if (pos == N) {	
		if (state == (1 << 10) - 1) return 1;		
		else return 0;
	}
	long long& ret = table[state][num][pos];
	if (ret != -1) return ret;
	ret = 0;
	if (num > 0) ret = (ret + DP((state | (1 << (num - 1))), num - 1, pos + 1)) % mod;
	if (num < 9) ret = (ret + DP((state | (1 << (num + 1))), num + 1, pos + 1)) % mod;
	return ret;
}