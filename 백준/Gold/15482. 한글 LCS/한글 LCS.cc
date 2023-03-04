#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

string A, B;
int lenA, lenB;
int table[1001][1001];

int cmp(int i, int j);
int DP(int a, int b);

void solve() {
	cin >> A >> B;
	lenA = A.length() / 3;
	lenB = B.length() / 3;
	memset(table, -1, sizeof(table));
	cout << DP(0, 0);
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int cmp(int i, int j) {
	if (A[i * 3] == B[j * 3] && A[i * 3 + 1] == B[j * 3 + 1] && A[i * 3 + 2] == B[j * 3 + 2]) return 1;
	else return 0;
}

int DP(int a, int b) {
	if (a >= lenA || b >= lenB) return 0;
	if (a == lenA - 1 && b == lenB - 1) return cmp(a, b);
	int& ret = table[a][b];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, DP(a + 1, b));
	ret = max(ret, DP(a, b + 1));
	if (cmp(a, b) == 1) ret = max(ret, 1 + DP(a + 1, b + 1));
	return ret;
}