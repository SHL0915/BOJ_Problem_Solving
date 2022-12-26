#include <bits/stdc++.h>
using namespace std;

map <long long, long long> table;
long long N, P, Q;

long long DP(long long A);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	table[0] = 1;
	cin >> N >> P >> Q;
	cout << DP(N);
	return 0;
}

long long DP(long long A) {
	long long& ret = table[A];
	if (ret != 0) return ret;
	ret = DP(A / P) + DP(A / Q);
	return ret;
}