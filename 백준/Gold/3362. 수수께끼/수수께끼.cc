#include <iostream>
#include <queue>
using namespace std;

int T, N, K, ans;
long long coin, status;

struct cmp {
	bool operator() (int A, int B) {
		return A > B;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {		
		int flag = 0;	
		status = 1;
		cin >> N >> K;
		priority_queue <int, vector <int>, cmp> c;
		for (int i = 0; i < N; i++) {
			cin >> coin;
			c.push(coin);
			if (flag == 1) continue;
			while (c.size() && c.top() <= status) {				
				status += c.top();
				c.pop();
			}
			if (status > K) {
				cout << i + 1 << '\n';
				flag = 1;				
			}
		}
		if (flag == 0) cout << -1 << '\n';
	}
	return 0;
}