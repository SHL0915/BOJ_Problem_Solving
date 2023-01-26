#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
	cin >> N;
	ll ans = 0;
	priority_queue <int, vector <int>, greater<>> pq;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		if (pq.size() == 0) pq.push(a);
		else {
			while (pq.size()) {
				if (pq.top() < a) {
					ans += a - pq.top();
					pq.pop();
					pq.push(a);
				}
				else break;
			}
			pq.push(a);
		}
	}
	cout << ans << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}