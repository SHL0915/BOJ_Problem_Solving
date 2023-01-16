#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;

bool isPalindrome(int left, int right);

void solve() {
	cin >> S;
	if (isPalindrome(0, S.length() - 1)) cout << "AKARAKA";
	else cout << "IPSELENTI";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

bool isPalindrome(int left, int right) {
	int len = right - left + 1;
	if (len == 1) return true;
	else if (len == 2) return (S[left] == S[right]);
	for (int i = 0; i < len / 2; i++) {
		if (S[left + i] != S[right - i]) return false;
	}
	return isPalindrome(left, left + len / 2 - 1);
}