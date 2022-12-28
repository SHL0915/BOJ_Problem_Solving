#include <bits/stdc++.h>
using namespace std;
const int mod = 1000;

int A, B, D, N, ans;
int table[1000001];
int psum[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> D >> N;
	table[0] = 1;
	psum[0] = 1;
	for (int i = 1; i <= N; i++) {
		int r = (i - A < 0) ? 0 : psum[i - A];
		int l = (i - B < 0) ? 0 : psum[i - B];
		table[i] = (r - l < 0) ? (r - l + mod) : (r - l);
		psum[i] = (psum[i - 1] + table[i]) % mod;	
	}
	ans = psum[N] - psum[N - D];
	if (ans < 0) ans += mod;
	cout << ans;
	return 0;
}