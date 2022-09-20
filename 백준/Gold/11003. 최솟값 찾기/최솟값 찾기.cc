#include <iostream>
#include <queue>
using namespace std;

struct dqdata {
	int val, index;
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, L, input;
	deque <dqdata> dq;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> input;		
		while (dq.size() && input < dq.back().val)	
			dq.pop_back();
		while (dq.size() && dq.front().index <= i - L)	
			dq.pop_front();
		dq.push_back({ input, i });
		cout << dq.front().val << " ";
	}
	return 0;
}