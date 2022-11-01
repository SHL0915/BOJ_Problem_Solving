#include <iostream>
using namespace std;

int T;
string paper;

bool check(string S);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> paper;
		if (check(paper) == false) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}

bool check(string S) {
	if (S.length() == 1) return true;
	string left = "", right = "";
	for (int i = 0; i < S.length() / 2; i++) {
		left += S[i];
		right += S[S.length() - 1 - i];
	}
	for (int i = 0; i < right.length(); i++) {
		if (right[i] == '0') right[i] = '1';
		else right[i] = '0';
	}
	if (left == right) return check(left);
	else return false;
}