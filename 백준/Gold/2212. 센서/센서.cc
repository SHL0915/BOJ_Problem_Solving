#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
vector <int> arr;

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	priority_queue <int> pq;
	for (int i = 1; i < arr.size(); i++) pq.push(arr[i] - arr[i - 1]);

	int ans = arr.back() - arr.front();
	for (int i = 0; i < K - 1; i++) {
		if (pq.size()) {
			ans -= pq.top();
			pq.pop();
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