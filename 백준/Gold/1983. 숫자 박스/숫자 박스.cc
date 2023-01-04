#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int INIT = 0x7f7f7f7f;

int N;
vector <int> A, B;
int table[401][401][401];

int DP(int pos, int a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a != 0) A.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a != 0) B.push_back(a);
	}
	memset(table, INIT, sizeof(table));
	cout << DP(0, 0, 0);
	return 0;
}

int DP(int pos, int a, int b) {
	if (pos == N) {
		if (a == A.size() && b == B.size()) return 0;
		else return -INF;	
	}
	int& ret = table[pos][a][b];
	if (ret != INIT) return ret;
	ret = -INF;
	if (a < A.size() && b < B.size()) ret = max(ret, A[a] * B[b] + DP(pos + 1, a + 1, b + 1));
	if (a < A.size()) ret = max(ret, DP(pos + 1, a + 1, b));
	if (b < B.size()) ret = max(ret, DP(pos + 1, a, b + 1));
	ret = max(ret, DP(pos + 1, a, b));
	return ret;
}