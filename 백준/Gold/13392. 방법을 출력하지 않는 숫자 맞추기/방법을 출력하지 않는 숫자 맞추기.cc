#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 10;

int N;
string A, B;
long long table[10001][11][11];
int num[10001];

long long DP(int pos, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> A >> B;
	for (int i = 0; i < A.size(); i++) num[i] = A[i] - '0';
	memset(table, -1, sizeof(table));
	cout << DP(0, 0, 0);
	return 0;
}

long long DP(int pos, int left, int right) {
	if (pos == N) return 0;
	long long& ret = table[pos][left][right];
	if (ret != -1) return ret;
	ret = INF;
	int now_num = (num[pos] - right + left + mod) % mod;
	if (now_num == B[pos] - '0') ret = min(ret, DP(pos + 1, left, 0));
	else {
		ret = min(ret, 1 + DP(pos, (left + 1) % mod, right));
		ret = min(ret, 1 + DP(pos, left, (right + 1) % mod));
	}
	return ret;
}