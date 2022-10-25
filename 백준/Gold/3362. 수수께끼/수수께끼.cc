#include <iostream>
#include <queue>
using namespace std;

int T, N, K, ans;
long long status;
int coin[100000];

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
		ans = -1;
		status = 1;
		cin >> N >> K;
		priority_queue <int, vector <int>, cmp> c;
		for (int i = 0; i < N; i++) cin >> coin[i];
		for (int i = 0; i < N; i++) {
			c.push(coin[i]);
			while (c.size() && c.top() <= status) {				
				status += c.top();
				c.pop();
			}
			if (status > K) {
				ans = i + 1 ;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}