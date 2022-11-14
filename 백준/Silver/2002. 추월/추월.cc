#include <iostream>
#include <set>
#include <queue>
using namespace std;

int N, ans;
set <string> s;
deque <string> dq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		dq.push_back(input);
		s.insert(input);
	}
	for (int i = 0; i < N; i++) {
		while (dq.size()) {
			if (s.count(dq.front()) == 0) dq.pop_front();
			else break;
		}
		string input;
		cin >> input;
		if (input != dq.front()) {
			ans++;
			s.erase(input);
		}
		else {
			dq.pop_front();
			s.erase(input);
		}
	}
	cout << ans;
	return 0;
}