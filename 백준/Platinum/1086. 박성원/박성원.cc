#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K, ans;
ll arr[16][101];
string s[16];
ll table[(1 << 16)][101];

ll GCD(ll A, ll B) {
	if (A > B) {
		if (A % B == 0) return B;
		else return GCD(A % B, B);
	}
	else {
		if (B % A == 0) return A;
		else return GCD(B % A, A);
	}
}

ll DP(ll state, ll mod) {
	if (state == (1 << N) - 1) {
		return (mod == 0);
	}
	ll& ret = table[state][mod];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < N; i++) {
		if (state & (1 << i)) continue;
		ret += DP(state | (1 << i), arr[i][mod]);
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> s[i];
	cin >> K;
	for (int i = 0; i < N; i++) {
		ll len = s[i].length();
		for (int j = 0; j <= K; j++) {
			ll cnt = j % K;
			for (int a = 0; a < len; a++) {
				cnt *= 10;
				cnt += (s[i][a] - '0');
				cnt %= K;
			}
			arr[i][j] = cnt;
		}
	}
	memset(table, -1, sizeof(table));
	ans = DP(0, 0);
	ll tot = 1;
	for (int i = 2; i <= N; i++) tot *= i;
	if (ans == 0) cout << "0/1";
	else if (ans == tot) cout << "1/1";
	else cout << ans / GCD(ans, tot) << "/" << tot / GCD(ans, tot);
	return 0;
}