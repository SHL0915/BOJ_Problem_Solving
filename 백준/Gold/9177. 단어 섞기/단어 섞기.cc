#include <bits/stdc++.h>
using namespace std;

int t, tc;
string A, B, C;
int table[201][201];

int DP(int a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		tc++;
		cin >> A >> B >> C;
		memset(table, -1, sizeof(table));
		cout << "Data set " << tc << ": ";
		if (DP(0, 0) == 1) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}

int DP(int a, int b) {
	if (a + b == C.size()) return 1;
	int& ret = table[a][b];
	if (ret != -1) return ret;
	ret = 0;
	if (a < A.size() && A[a] == C[a + b]) ret |= DP(a + 1, b);
	if (b < B.size() && B[b] == C[a + b]) ret |= DP(a, b + 1);
	return ret;
}