#include <iostream>
#include <deque>
using namespace std;

int N, M, cnt;
deque <int> dq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) dq.push_back(i);
	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == input) {
				if (i < dq.size() - i) {
					while (dq.front() != input) {
						dq.push_back(dq.front());
						dq.pop_front();
						cnt++;
					}
					dq.pop_front();
					break;
				}
				else {
					while (dq.front() != input) {
						dq.push_front(dq.back());
						dq.pop_back();
						cnt++;
					}
					dq.pop_front();
					break;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}