#include <iostream>
using namespace std;

int T;
int alph[26];

int main(void) {
	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 26; j++) alph[j] = 0;
		string S;
		cin >> S;
		for (int j = 0; j < S.length(); j++) {
			if (++alph[S[j] - 'A'] % 3 == 0) {
				if (j == S.length() - 1) {
					cout << "FAKE\n";
					break;
				}
				else if (S[j + 1] != S[j]) {
					cout << "FAKE\n";
					break;
				}
				else j++;
			}
			if (j == S.length() - 1) cout << "OK\n";
		}
	}
	return 0;
}