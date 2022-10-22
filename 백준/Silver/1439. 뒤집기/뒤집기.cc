#include <iostream>
using namespace std;

string S;
int numZ, numO;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	if (S[0] == '0') numZ++;
	else numO++;
	for (int i = 1; i < S.length(); i++) {
		if (S[i] != S[i - 1]) {
			if (S[i] == '0')numZ++;
			else numO++;
		}
	}
	cout << min(numO, numZ);
	return 0;
}