#include <bits/stdc++.h>
using namespace std;

string S;

int convert(string s);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	for (int i = 0; i < S.length() - 1; i++) {
		string A = "", B = "";
		for (int j = 0; j <= i; j++) A += S[j];
		for (int j = i + 1; j < S.length(); j++) B += S[j];		
		if (convert(A) == convert(B)) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}

int convert(string s) {
	int ret = 1;
	for (int i = 0; i < s.length(); i++) ret *= (s[i] - '0');
	return ret;
}