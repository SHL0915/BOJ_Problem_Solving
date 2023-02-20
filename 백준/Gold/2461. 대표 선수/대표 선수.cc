#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, ans = 0x3f3f3f3f;
vector <int> arr[1001];
int idx[1001];
priority_queue <pii, vector<pii>, greater<>> pq;

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a; cin >> a;
			arr[i].push_back(a);
		}
		sort(arr[i].begin(), arr[i].end());
	}
	int val = 0;
	for (int i = 0; i < N; i++) {
		pq.push({ arr[i][0], i });
		val = max(val, arr[i][0]);
	}
	while (pq.size()) {
		ans = min(ans, val - pq.top().first);
		int now = pq.top().second;
		pq.pop();
		if (++idx[now] == M) break;
		val = max(val, arr[now][idx[now]]);
		pq.push({ arr[now][idx[now]], now });
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