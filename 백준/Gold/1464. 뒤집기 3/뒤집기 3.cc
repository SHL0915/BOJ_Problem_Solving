#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void) {
	deque <char> d;
	string s;
	cin >> s;
	int i, reverse = 0;
	char min = s[0];
	d.push_back(s[0]);
	for (i = 1; i < s.size(); i++) {
		if (s[i] <= min) {
			min = s[i];
			d.push_front(s[i]);
		}
		else
			d.push_back(s[i]);
	}
	for (i = 0; i < d.size(); i++) {
		cout << d[i];
	}
	return 0;
}