#include <bits/stdc++.h>
using namespace std;

long long cnt = 0;
stack <pair<int, int>> s;
string input;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') s.push({ 0, i });		
		else {
			if (s.top().second == i - 1) {
				s.pop();
				cnt += s.size();
			}
			else s.pop();
		}
	}
	cout << cnt;
	return 0;
}