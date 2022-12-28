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
		int r, l;
		if (i - A < 0) r = 0;
		else r = psum[i - A];
		if (i - B < 0) l = 0;
		else l = psum[i - B];
		table[i] = r - l;
		if (table[i] < 0) table[i] += mod;
		psum[i] = (psum[i - 1] + table[i]) % mod;		
	}
	ans = psum[N] - psum[N - D];
	if (ans < 0) ans += mod;
	cout << ans;
	return 0;
}