#include <bits/stdc++.h>
using namespace std;

int N, Q, state, output;
deque <int> arr[2];
set <int> s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin >> N >> Q;
	while (Q--) {
		int A, B;
		cin >> A;
		if (A == 0) {
			cin >> B;
			arr[state].push_back(B);
		}
		else if (A == 1) {
			for (int i = 0; i < 2; i++) {
				while (arr[i].size()) {
					s.insert(arr[i].back());
					arr[i].pop_back();
				}
			}
			state = 0;
		}
		else if (A == 2) state ^= 1;
		else {			
			if (arr[state].size() != 0) {
				output = arr[state].back();
				arr[state].pop_back();				
			}
			else if(s.size()) {
				if (state == 0) output = *s.begin();
				else output = *s.rbegin();
				s.erase(output);
			}
			else {
				output = arr[state ^ 1].front();
				arr[state ^ 1].pop_front();
			}
			cout << output << '\n';
		}
	}
	return 0;
}