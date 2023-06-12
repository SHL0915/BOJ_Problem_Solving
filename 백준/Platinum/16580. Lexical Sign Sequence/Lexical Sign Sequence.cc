#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
int arr[100005];
int ans[100005];
int psum[100005];
pair<pii, int> q[100005];
priority_queue <pii, vector<pii>, greater<>> pq;

void solve() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		ans[i] = arr[i];
		if (arr[i] == 0) ans[i] = 1;
	}

	for (int i = 1; i <= N; i++) psum[i] = psum[i - 1] + ans[i];

	for (int i = 0; i < Q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		q[i] = { {a,b},c };
	}
		
	sort(q, q + Q, [&](pair<pii, int> a, pair<pii, int> b) {
		if (a.first.first == b.first.first) return a.first.second < b.first.second;
		return a.first.first < b.first.first;
		});

	int now = 0, idx = 0;
	for (int i = 1; i <= N; i++) {

		for (idx; idx < Q; idx++) {
			int l = q[idx].first.first, r = q[idx].first.second;
			if (l <= i) {
				int M = psum[r] - psum[l - 1];
				pq.push({ M - q[idx].second - now, q[idx].first.second });
			}
			else break;
		}

		while (pq.size()) {
			pii t = pq.top();
			if (t.second < i) {
				pq.pop();
				continue;
			}
			else break;
		}

		if (pq.size() == 0) {
			if (arr[i] == 0) ans[i] = -1;
		}
		else {
			pii t = pq.top();
			int val = t.first;

			val += now;

			if (val < 0) {
				cout << "Impossible";
				return;
			}
			else {
				if (arr[i] == 0) {
					if (val >= 2) {
						ans[i] = -1;
						now -= 2;
					}
				}
			}
		}
	}
	
	for (int i = 1; i <= N; i++) cout << ans[i] << " ";
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