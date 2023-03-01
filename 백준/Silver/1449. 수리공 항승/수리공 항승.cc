#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, L;
int arr[1001];
int covered[2001];

void solve() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int now = arr[i];
		if (covered[now]) continue;
		ans++;
		for (int j = now; j < now + L; j++) covered[j] = 1;		
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