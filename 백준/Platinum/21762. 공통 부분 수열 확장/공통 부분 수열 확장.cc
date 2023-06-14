#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string X, Y, W;
int Af[200005], Bf[200005];
int Ab[200005], Bb[200005];
int cnt[26], chk[26];

void solve() {
	cin >> X >> Y >> W;
	for (int i = 0, ptr = 0; i < X.length(); i++) {
		if (ptr == W.length()) break;
		if (X[i] == W[ptr]) {
			Af[ptr] = i;
			ptr++;
		}
	}
	for (int i = 0, ptr = 0; i < Y.length(); i++) {
		if (ptr == W.length()) break;
		if (Y[i] == W[ptr]) {
			Bf[ptr] = i;
			ptr++;
		}
	}
	for (int i = X.length() - 1, ptr = W.length() - 1; i >= 0; i--) {
		if (ptr == -1) break;
		if (X[i] == W[ptr]) {
			Ab[ptr] = i;
			ptr--;
		}
	}	
	for (int i = Y.length() - 1, ptr = W.length() - 1; i >= 0; i--) {
		if (ptr == -1) break;
		if (Y[i] == W[ptr]) {
			Bb[ptr] = i;
			ptr--;
		}
	}

	Ab[W.length()] = X.length();
	Bb[W.length()] = Y.length();

	memset(cnt, 0, sizeof(cnt));
	memset(chk, 0, sizeof(chk));

	for (int i = 0; i < Ab[0]; i++) cnt[X[i] - 'a']++;
	for (int i = 0; i < Bb[0]; i++) chk[Y[i] - 'a']++;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] != 0 && chk[i] != 0) {
			cout << 1 << '\n';
			return;
		}
	}

	memset(cnt, 0, sizeof(cnt));
	memset(chk, 0, sizeof(chk));

	for (int i = Af[0] + 1; i < Ab[1]; i++) cnt[X[i] - 'a']++;
	for (int i = Bf[0] + 1; i < Bb[1]; i++) chk[Y[i] - 'a']++;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] != 0 && chk[i] != 0) {
			cout << 1 << '\n';
			return;
		}
	}

	for (int i = 1; i < W.length(); i++) {
		for (int j = Af[i - 1] + 1; j <= min(Af[i], Ab[i] - 1); j++) cnt[X[j] - 'a']--;
		for (int j = max(Ab[i], Af[i] + 1); j < Ab[i + 1]; j++) cnt[X[j] - 'a']++;

		for (int j = Bf[i - 1] + 1; j <= min(Bf[i], Bb[i] - 1); j++) chk[Y[j] - 'a']--;
		for (int j = max(Bb[i], Bf[i] + 1); j < Bb[i + 1]; j++) chk[Y[j] - 'a']++;
		
		for (int j = 0; j < 26; j++) {
			if (cnt[j] != 0 && chk[j] != 0) {
				cout << 1 << '\n';
				return;
			}
		}
	}

	cout << 0 << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}