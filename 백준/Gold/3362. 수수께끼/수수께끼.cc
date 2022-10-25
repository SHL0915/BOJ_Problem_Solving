#include <iostream>
#include <queue>
using namespace std;

int T, N, K, ans;
int coin;

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
		cin >> N >> K;
		priority_queue <int, vector <int>, cmp> pq, c;
		for (int i = 1; i <= K; i++) pq.push(i);
		for (int i = 0; i < N; i++) {
			cin >> coin;
			c.push(coin);
			if (flag == 1) continue;
			while (pq.size() && c.size() && c.top() <= pq.top()) {				
				int temp = pq.top();
				while (pq.size() && pq.top() <= temp + c.top() - 1) pq.pop();
				c.pop();
			}
			if (pq.size() == 0) {
				cout << i + 1 << '\n';
				flag = 1;				
			}
		}
		if (flag == 0) cout << -1 << '\n';
	}
	return 0;
}