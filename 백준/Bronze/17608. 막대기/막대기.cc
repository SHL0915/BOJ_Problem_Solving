#include <bits/stdc++.h>
using namespace std;

int N;
stack <int> s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (s.size() == 0) s.push(a);
		else {
			while (s.size()) {
				if (s.top() <= a) s.pop();
				else break;
			}
			s.push(a);
		}
	}
	cout << s.size();
	return 0;
}