#include <iostream>
#include <queue>
using namespace std;

int n, a;
priority_queue <int> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			int val;
			cin >> val;
			pq.push(val);
		}
		if (a == 0) {
			if (pq.size()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else cout << -1 << "\n";			
		}
	}
	return 0;
}