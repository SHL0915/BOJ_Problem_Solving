#include <bits/stdc++.h>
using namespace std;

int T, N, M;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		priority_queue <int> pq;
		queue <pair<int, int>> q;
		cin >> N >> M;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			q.push({ a,i });
			pq.push(a);
		}
		while (q.size()) {
			if (q.front().first == pq.top()) {
				if (q.front().second == M) {
					cnt++;
					cout << cnt << '\n';
					break;
				}
				else {
					cnt++;
					q.pop();
					pq.pop();
				}
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}
	return 0;
}