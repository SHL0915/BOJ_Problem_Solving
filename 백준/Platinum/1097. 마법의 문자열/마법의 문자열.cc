#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, K, ans;
string arr[8];
int bt[8];
int mark[8];
int pi[200];
vector<int> match;

void kmp(string s, string cmp);
void makePi(string s);
void BackTracking(int k);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> K;
	BackTracking(0);
	cout << ans;
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

void kmp(string s, string cmp) {
	memset(pi, 0, sizeof(pi));
	makePi(cmp);
	int n = s.length(), m = cmp.length(), pos = 0, k = 0;
	while (pos < n / 2) {
		if (k < m && s[pos + k] == cmp[k]) {
			k++;
			if (k == m) match.push_back(pos);
		}
		else {
			if (k == 0) pos++;
			else {
				pos += k - pi[k - 1];
				k = pi[k - 1];
			}
		}
	}
	return;
}

void makePi(string s) {
	int n = s.length(), pos = 1, k = 0;
	while (pos + k < n) {
		if (s[pos + k] == s[k]) {
			k++;
			pi[pos + k - 1] = k;
		}
		else {
			if (k == 0) pos++;
			else {
				pos += k - pi[k - 1];
				k = pi[k - 1];
			}
		}
	}
	return;
}

void BackTracking(int k) {
	if (k == N) {
		string S = "", T = "";
		for (int i = 0; i < N; i++) T += arr[bt[i]];
		S = T + T;
		match.clear();
		kmp(S, T);
		if (match.size() == K) ans++;
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (mark[i] == 0) {
				mark[i] = 1;
				bt[k] = i;
				BackTracking(k + 1);
				mark[i] = 0;
			}
		}
	}
}