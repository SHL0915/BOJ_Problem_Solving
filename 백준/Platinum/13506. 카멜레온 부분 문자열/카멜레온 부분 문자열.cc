#include <bits/stdc++.h>
using namespace std;

string S;
int pi[1000000];
vector <int> ans;

void makepi(string s);
void kmp(string org, string cmp);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	makepi(S);
	for (int i = pi[S.length() - 1]; i >= 1; i--) {
		string s = "";
		for (int j = 0; j < i; j++) s += S[j];
		kmp(S, s);
		if (ans.size() >= 3 && ans.front() == 0 && ans.back() == S.length() - i) {
			cout << s;
			return 0;
		}
	}
	cout << -1;
	return 0;
}

void makepi(string s) {
	int n = s.length();
	int pos = 1, k = 0;
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
}

void kmp(string org, string cmp) {
	int n = org.length(), m = cmp.length();
	int pos = 0, k = 0;
	while (pos + m <= n) {
		if (k < m && org[pos + k] == cmp[k]) {
			k++;
			if (k == m) ans.push_back(pos);
		}
		else {
			if (k == 0) pos++;
			else {
				pos += (k - pi[k - 1]);
				k = pi[k - 1];
			}
		}
	}
}