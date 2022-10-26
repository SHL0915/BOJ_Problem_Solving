#include <iostream>
using namespace std;

string s, t, A, B;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	A = s;
	B = t;
	while (A.length() != B.length()) {		
		if (A.length() < B.length()) A += s;
		else B += t;
	}
	if (A == B) cout << 1;
	else cout << 0;
	return 0;
}