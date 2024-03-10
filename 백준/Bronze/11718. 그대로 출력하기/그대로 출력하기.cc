#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main() {
	string s;
	string result;
	int i;
	for (i = 0; i < 100; i++) {
		getline(cin, s);
		if (s.length() == 0)
			break;
        cout << s << '\n';
	}
	return 0;
}