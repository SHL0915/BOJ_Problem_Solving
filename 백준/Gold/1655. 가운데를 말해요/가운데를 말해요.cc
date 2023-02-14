#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
priority_queue <int> l;
priority_queue <int, vector<int>, greater<>> r;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (l.size() == r.size()) l.push(x);
		else r.push(x);
		if (r.size() != 0) {
			if (l.top() > r.top()) {
				int lt = l.top(), rt = r.top();
				l.pop();
				r.pop();
				l.push(rt);
				r.push(lt);
			}
		}
		cout << l.top() << '\n';
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