#include <bits/stdc++.h>
using namespace std;

int N, K;
queue <int> q;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) q.push(i);
	cout << '<';
	while (q.size() > 1) {
		for (int i = 0; i < K - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << '>';
	return 0;
}