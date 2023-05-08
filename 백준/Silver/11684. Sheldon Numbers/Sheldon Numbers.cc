#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll X, Y, ans;
map <ll, int> mark;

void BruteForce(int len, int A_len);

void solve() {
	cin >> X >> Y;
	for (int i = 1; i < 64; i++) {
		for (int j = 1; j <= i; j++) {
			BruteForce(i, j);
		}
	}

	cout << ans;
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

void BruteForce(int len, int A_len) {
	string one = "";
	for (int i = 0; i < A_len; i++) one += '1';
	for (int i = 1; i <= len / A_len; i++) {
		int remain = len - A_len * i;
		if (i == 1) {
			if (remain == 0) {
				string s = one;
				ll val = 0;
				for (int j = 0; j < s.length(); j++) {
					val *= 2;
					val += s[j] - '0';
				}
				if (val >= X && val <= Y) {
					if (mark[val] == 0) {
						mark[val] = 1;
						ans++;
					}
				}
			}
			else {
				string s = one;
				for (int j = 0; j < remain; j++) s += '0';
				ll val = 0;
				for (int j = 0; j < s.length(); j++) {
					val *= 2;
					val += s[j] - '0';
				}
				if (val >= X && val <= Y) {
					if (mark[val] == 0) {
						mark[val] = 1;
						ans++;
					}
				}
			}
		}
		else {
			if (remain % (i - 1) == 0) {
				string s = "";
				string zero = "";
				for (int j = 0; j < remain / (i - 1); j++) zero += '0';
				for (int j = 0; j < i - 1; j++) {
					s += one;
					s += zero;
				}
				s += one;
				ll val = 0;
				for (int j = 0; j < s.length(); j++) {
					val *= 2;
					val += s[j] - '0';
				}
				if (val >= X && val <= Y) {
					if (mark[val] == 0) {
						mark[val] = 1;
						ans++;
					}
				}
			}
			if (remain % i == 0) {
				string s = "";
				string zero = "";
				for (int j = 0; j < remain / i; j++) zero += '0';
				for (int j = 0; j < i; j++) {
					s += one;
					s += zero;
				}
				ll val = 0;
				for (int j = 0; j < s.length(); j++) {
					val *= 2;
					val += s[j] - '0';
				}
				if (val >= X && val <= Y) {
					if (mark[val] == 0) {
						mark[val] = 1;
						ans++;
					}
				}
			}
		}
	}
	return;
}