#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator() (int A, int B) {
		return A > B;
	}
};

int N, Q, state;
priority_queue <int> upper;
priority_queue <int, vector<int>, cmp> lower;
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
			s.insert(B);
		}
		else if (A == 1) {
			for (int i = 0; i < 2; i++) {
				while (arr[i].size()) {
					upper.push(arr[i].back());
					lower.push(arr[i].back());
					arr[i].pop_back();
				}
			}
			state = 0;
		}
		else if (A == 2) state ^= 1;
		else {
			while (lower.size()) {
				if (s.count(lower.top()) == 0) lower.pop();
				else break;
			}
			while (upper.size()) {
				if (s.count(upper.top()) == 0) upper.pop();
				else break;
			}
			if (arr[state].size() != 0) {
				cout << arr[state].back() << '\n';
				s.erase(arr[state].back());
				arr[state].pop_back();				
			}
			else {
				if (state == 0 && lower.size() != 0) {
					cout << lower.top() << '\n'; 
					s.erase(lower.top());
					lower.pop();
				}
				else if(state == 1 && upper.size() != 0) {
					cout << upper.top() << '\n';
					s.erase(upper.top());
					upper.pop();
				}
				else {
					cout << arr[state ^ 1][0] << '\n';
					s.erase(arr[state ^ 1][0]);
					arr[state ^ 1].pop_front();
				}
			}
		}
	}
	return 0;
}