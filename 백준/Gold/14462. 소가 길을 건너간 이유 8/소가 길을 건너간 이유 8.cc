#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int A[1001], B[1001];
int table[1001][1001];

int DP(int a, int b);
int absol(int a);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	memset(table, -1, sizeof(table));
	cout << DP(0, 0);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int DP(int a, int b) {
	if (a == N || b == N) return 0;
	int& ret = table[a][b];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = b; i < N; i++) {
		if (absol(A[a] - B[i]) <= 4) ret = max(ret, 1 + DP(a + 1, i + 1));
	}
	ret = max(ret, DP(a + 1, b));
	return ret;
}

int absol(int a) {
	if (a < 0) return -a;
	else return a;
}