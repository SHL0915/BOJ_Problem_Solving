#include <iostream>
#include <stack>
using namespace std;

string input;

int main(void) {
	for (int i = 1; ; i++) {
		cin >> input;
		int cnt = 0;
		stack <char> s;
		if (input[0] == '-') break;
		for (int j = 0; j < input.length(); j++) {
			if (s.size() == 0) {
				if (input[j] == '}') cnt++;
				s.push('{');
			}
			else {
				if (input[j] == '{') s.push('{');
				else s.pop();
			}
		}
		cnt += s.size() / 2;
		cout << i << ". " << cnt << "\n";
	}
	return 0;
}