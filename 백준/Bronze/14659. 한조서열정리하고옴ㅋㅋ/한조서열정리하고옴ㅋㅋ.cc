#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
stack <pii> s;

void solve() {
	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		if (s.size() == 0) s.push({ a,i });
		else {
			if (a > s.top().first) {
				while (s.size()) {
					if (a > s.top().first) {
						ans = max(ans, i - s.top().second - 1);
						s.pop();
					}
					else break;
				}
				s.push({ a,i });
			}
			else s.push({ a,i });
		}
	}
	while (s.size()) {
		ans = max(ans, N - s.top().second - 1);
		s.pop();
	}
	cout << ans;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}