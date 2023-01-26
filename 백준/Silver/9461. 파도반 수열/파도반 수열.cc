#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[101];

void solve() {
	cin >> N;
	cout << arr[N] << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	for (int i = 4; i <= 100; i++) arr[i] = arr[i - 3] + arr[i - 2];
	cin >> t;
	while (t--) solve();
	return 0;
}