#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
	cin >> N;
	int add = 0, cnt = 0;
	priority_queue <pii, vector<pii>, greater<>> pq;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		pq.push({ a,b });
	}
	for (int i = 0; ; i++) {
		if (pq.size() == 0) break;
		add++;
		if (!(i % 7 == 5 || i % 7 == 6)) {
			pii t = pq.top();
			pq.pop();
			t.second--;
			if (t.second) pq.push(t);
		}
		while (pq.size()) {
			pii t = pq.top();
			if (t.first == i + 1) {
				if (t.second > add) {
					cout << -1;
					return;
				}
				add -= t.second;
				cnt += t.second;
				pq.pop();
			}
			else break;
		}
	}
	cout << cnt;
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