#include <bits/stdc++.h>
using namespace std;

int P;
int N, K;
long long table[101][101][101];

long long DP(int pos, int cont, int num);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> P;
	while (P--) {
		cin >> N >> K;
		memset(table, -1, sizeof(table));
		cout << DP(0, 0, 0) << '\n';
	}
	return 0;
}

long long DP(int pos, int cont, int num) {
	if (pos == N) {
		if (num == K) return 1;
		else return 0;
	}
	long long& ret = table[pos][cont][num];
	if (ret != -1) return ret;
	ret = 0;
	ret += DP(pos + 1, 0, num);
	ret += DP(pos + 1, cont + 1, num + (cont > 0));
	return ret;
}