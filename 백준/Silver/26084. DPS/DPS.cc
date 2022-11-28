#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
int N;
ll ans = 1;
int handle[26];
int cnt[26];
ll table[50001][4];

ll combination(ll N, ll K);


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	cin >> N;
	for (int i = 0; i < 3; i++) cnt[S[i] - 'A']++;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		handle[s[0] - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] == 0) continue;
		if (handle[i] == 0) {
			cout << 0;
			return 0;
		}
		else ans *= combination(handle[i], cnt[i]);
	}
	cout << ans;
	return 0;
}

ll combination(ll N, ll K) {
	if (K == 0 || N == K) return 1;
	else if (table[N][K] != 0) return table[N][K];
	table[N][K] = combination(N - 1, K) + combination(N - 1, K - 1);
	return table[N][K];
}