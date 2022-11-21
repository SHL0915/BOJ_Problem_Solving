#include <iostream>
using namespace std;

int N, flag;
string pattern;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> pattern;
	string f = "", b = "";
	for (int i = 0; i < pattern.length(); i++) {
		if (pattern[i] == '*') {
			flag = 1;
			continue;
		}
		if (flag == 0) f += pattern[i];
		else b += pattern[i];
	}
	for (int i = 0; i < N; i++) {
		flag = 0;
		string s;
		cin >> s;
		if (s.length() < f.length() + b.length()) {
			cout << "NE\n";
			continue;
		}
		for (int i = 0; i < f.length(); i++) {
			if (s[i] != f[i]) {
				cout << "NE\n";
				flag = 1;
				break;
			}
		}
		if (flag == 1) continue;
		for (int i = 0; i < b.length(); i++) {
			if (s[s.length() - 1 - i] != b[b.length() - 1 - i]) {
				cout << "NE\n";
				flag = 1;
				break;
			}
		}
		if (flag == 1) continue;
		cout << "DA\n";
	}
	return 0;
}