#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

long long memo[100000] = {0};
long long N, D, input, maxVal;

struct dqData {
	long long val, index;
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	deque <dqData> dq;
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		cin >> input;
		while (dq.size() && dq.front().index < i - D) {
			dq.pop_front();
		}
		if (dq.size() == 0)
			maxVal = input;
		else
			maxVal = max(input, input + dq.front().val);	
		memo[i] = maxVal;
		while (dq.size()) {
			if (maxVal >= dq.back().val)
				dq.pop_back();
			else
				break;
		}
		dq.push_back({ maxVal, i });
	}
	maxVal = -1000000000;
	for (int i = 0; i < N; i++) 
		maxVal = max(maxVal, memo[i]);	
	cout << maxVal;
	return 0;	
}