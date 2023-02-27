#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string arr[5];

void solve() {
	for (int i = 0; i < 5; i++) cin >> arr[i];
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (i >= arr[j].length()) continue;
			cout << arr[j][i];
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