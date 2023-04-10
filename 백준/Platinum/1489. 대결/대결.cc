#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int A[51];
int B[51];
int table[51][51][51][51];

int DP(int a, int b, int cand, int back);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	sort(A, A + N);
	sort(B, B + N);

	memset(table, -1, sizeof(table));
	cout << DP(0, 0, 0, N - 1);
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

int DP(int a, int b, int cand, int back) {
	if (a == N) return 2 * cand;
	int& ret = table[a][b][cand][back];
	if (ret != -1) return ret;
	ret = 0;

	if (A[a] > B[b]) ret = max(ret, DP(a + 1, b + 1, cand + 1, back));
	else if (A[a] == B[b]) {
		ret = max(ret, 1 + DP(a + 1, b + 1, cand, back));
		ret = max(ret, DP(a + 1, b, cand, back - 1));
	}
	else {
		if (cand) ret = max(ret, 2 + DP(a + 1, b, cand - 1, back));
		else ret = max(ret, DP(a + 1, b, cand, back - 1));
	}

	return ret;
}