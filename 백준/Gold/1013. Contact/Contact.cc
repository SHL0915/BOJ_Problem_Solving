#include <iostream>
#include <regex>
using namespace std;

int T;
string input;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> input;
		regex re("(100+1+|01)+");
		if (regex_match(input, re) == true) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}