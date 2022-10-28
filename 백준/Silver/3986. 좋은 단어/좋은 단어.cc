#include <iostream>
#include <stack>
using namespace std;

int N, cnt;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--) {
		string input;
		cin >> input;
		stack <char> s;
		for (int i = 0; i < input.length(); i++) {
			if (s.size() == 0) s.push(input[i]);
			else if (s.top() == input[i]) s.pop();
			else s.push(input[i]);
		}
		if (s.size() == 0) cnt++;
	}
	cout << cnt;
	return 0;
}