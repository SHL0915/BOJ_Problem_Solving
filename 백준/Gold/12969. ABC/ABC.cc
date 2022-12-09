#include <bits/stdc++.h>
using namespace std;

int N, K;
bool table[31][31][31][900];
char ans[31];

bool DP(int A, int B, int C, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	if (DP(0, 0, 0, 0)) for (int i = 0; i < N; i++) cout << ans[i];
	else cout << -1;
	return 0;
}

bool DP(int A, int B, int C, int k) {
	if (A + B + C == N) {
		if (k == K) return true;
		else return false;
	}
	if (table[A][B][C][k]) return false;
	table[A][B][C][k] = true;
	ans[A + B + C] = 'A';
	if (DP(A + 1, B, C, k)) return true;
	ans[A + B + C] = 'B';
	if (DP(A, B + 1, C, k + A)) return true;
	ans[A + B + C] = 'C';
	if (DP(A, B, C + 1, k + A + B)) return true;
	return false;
}