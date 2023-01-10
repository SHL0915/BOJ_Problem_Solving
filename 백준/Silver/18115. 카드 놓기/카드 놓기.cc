#include <bits/stdc++.h>
using namespace std;

int N;
deque <int> dq;
int arr[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		int now = arr[N - i + 1];
		if (now == 1) dq.push_back(i);
		else if (now == 2) {
			int b = dq.back();
			dq.pop_back();
			dq.push_back(i);
			dq.push_back(b);
		}
		else dq.push_front(i);
	}
	for (int i = dq.size() - 1; i >= 0; i--) cout << dq[i] << " ";
	return 0;
}