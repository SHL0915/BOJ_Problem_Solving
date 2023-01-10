#include <bits/stdc++.h>
using namespace std;

int N, K, M, mode, cnt;
deque <int> dq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++) dq.push_back(i);
	while (dq.size()) {
		for (int i = 0; i < K - 1; i++) {
			if (mode) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			else {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		if (mode) {
			cout << dq.back() << '\n';
			dq.pop_back();
		}
		else {
			cout << dq.front() << '\n';
			dq.pop_front();
		}
		cnt++;
		if (cnt % M == 0) mode ^= 1;
	}	
	return 0;
}