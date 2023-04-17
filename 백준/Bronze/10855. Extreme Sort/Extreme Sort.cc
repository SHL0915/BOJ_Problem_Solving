#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[1500];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N - 1; i++) {
		if (arr[i + 1] < arr[i]) {
			cout << "no";
			return;
		}
	}
	cout << "yes";
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