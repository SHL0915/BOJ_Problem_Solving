#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct cmp {
	bool operator() (int a, int b) {
		if (abs(a) == abs(b)) return a > b;
		return abs(a) > abs(b);
	}
};

int N;
priority_queue <int, vector<int>, cmp> pq;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (x) pq.push(x);
		else {
			if (pq.size() == 0) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}