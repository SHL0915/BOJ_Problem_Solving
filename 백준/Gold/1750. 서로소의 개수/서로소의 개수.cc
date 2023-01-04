#include <bits/stdc++.h>
using namespace std;
const long long mod = 10000003;

int N;
int arr[51];
long long table[51][100001];

long long DP(int pos, int m);
int GCD(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	memset(table, -1, sizeof(table));
	cout << DP(0, 0);
	return 0;
}

long long DP(int pos, int m) {
	if (pos == N) return (m == 1);
	long long& ret = table[pos][m];
	if (ret != -1) return ret;
	ret = 0;
	if (m) ret += DP(pos + 1, GCD(m, arr[pos]));
	else ret += DP(pos + 1, arr[pos]);
	ret += DP(pos + 1, m);
	ret %= mod;
	return ret;
}

int GCD(int A, int B) {
	if (A > B) {
		if (A % B) return GCD(A % B, B);
		else return B;
	}
	else {
		if (B % A) return GCD(B % A, A);
		else return A;
	}
}