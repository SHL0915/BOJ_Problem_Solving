#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int C, N;
int chicken[20005];
pii cow[20005];

void solve() {
	cin >> C >> N;
	for (int i = 0; i < C; i++) cin >> chicken[i];
	sort(chicken, chicken + C);

	for (int i = 0; i < N; i++) cin >> cow[i].first >> cow[i].second;
	sort(cow, cow + N);

	priority_queue <int, vector<int>, greater<>> pq;
	int ptr = 0, ans = 0;
	for (int i = 0; i < C; i++) {
		while (ptr < N) {
			if (cow[ptr].first <= chicken[i]) {
				pq.push(cow[ptr].second);
				ptr++;
			}
			else break;
		}

		while (pq.size()) {
			int t = pq.top(); pq.pop();
			if (t < chicken[i]) continue;
			else {
				ans++;
				break;
			}
		}
	}

	cout << ans;
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