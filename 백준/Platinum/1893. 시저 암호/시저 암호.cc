#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string A, W, S;
int pi[50001];
map <char, int> idx;
vector <int> match, ans;

void makePi(string s);
void kmp(string s, string cmp, int shift);

void solve() {
	cin >> A >> W >> S;
	memset(pi, 0, sizeof(pi));
	idx.clear();
	ans.clear();
	makePi(W);
	for (int i = 0; i < A.length(); i++) idx[A[i]] = i;
	for (int i = 0; i < A.length(); i++) {
		match.clear();
		kmp(S, W, i);
		if (match.size() == 1) ans.push_back(i);
	}
	if (ans.size() == 0) cout << "no solution";
	else if (ans.size() == 1) cout << "unique: ";
	else cout << "ambiguous: ";
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
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
				pos += (k - pi[k - 1]);
				k = pi[k - 1];
			}
		}
	}
	return;
}

void kmp(string s, string cmp, int shift) {
	int n = s.length(), m = cmp.length(), pos = 0, k = 0;
	while (pos + m <= n) {
		char now = A[(idx[cmp[k]] + shift) % A.length()];
		if (k < m && s[pos + k] == now) {
			k++;
			if (k == m) match.push_back(pos);
		}
		else {
			if (k == 0) pos++;
			else {
				pos += (k - pi[k - 1]);
				k = pi[k - 1];
			}
		}
	}
	return;
}