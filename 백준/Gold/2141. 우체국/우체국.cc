#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[100005];

void solve() {
	cin >> N;
	
	ll tot = 0, sum = 0;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
		tot += arr[i].second;
	}

	sort(arr + 1, arr + N + 1);

	for (int i = 1; i <= N; i++) {
		sum += arr[i].second;
		if (sum * 2 >= tot) {
			cout << arr[i].first;
			return;
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