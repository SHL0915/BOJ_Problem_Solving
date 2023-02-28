#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[50001];
int mark[100001];
priority_queue <int, vector<int>, greater<>> pq;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		mark[arr[i]] = 1;
	}

	for (int i = 1; i <= 2 * N; i++) if (mark[i] == 0) pq.push(i);

	sort(arr, arr + N);

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		while (pq.size()) {
			if (pq.top() >= arr[i]) break;
			else pq.pop();
		}

		if (pq.size()) {
			cnt++;
			pq.pop();
		}
	}

	cout << cnt;
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