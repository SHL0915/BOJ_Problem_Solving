#include <iostream>
#include <deque>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	string s, explode;
	deque <char> d;
	stack <char> temp;
	int i, j;
	cin >> s >> explode;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == explode.back()) {
			temp.push(s[i]);
			for (j = explode.size() - 2; j >= 0; j--) {
				if (d.size() == 0 || d.back() != explode[j]) {
					while (temp.size()) {
						d.push_back(temp.top());
						temp.pop();
					}
					break;
				}
				else {
					temp.push(d.back());
					d.pop_back();
				}
			}
			while (temp.size()) temp.pop();
		}
		else {
			d.push_back(s[i]);
		}
	}
	if (d.size() == 0) {
		cout << "FRULA";
		return 0;
	}	
	for (i = 0; i < d.size(); i++) 
		cout << d[i];
	return 0;
}