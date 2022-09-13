#include <iostream>
#include <string>
using namespace std;

int num;

int isPalindrome(string * s);
int recursion(string * s, int l, int r);

int main(void) {
	int T;
	string s;
	cin >> T;
	for (int i = 0; i < T; i++) {
		num = 0;
		cin >> s;
		cout << isPalindrome(&s) << " " << num << "\n";
	}
	return 0;
}

int isPalindrome(string * s) {
	return recursion(s, 0, (*s).length() - 1);
}

int recursion(string * s, int l, int r) {
	num += 1;
	if (l >= r)
		return 1;
	else if ((*s)[l] != (*s)[r])
		return 0;
	else
		return recursion(s, l + 1, r - 1);
}