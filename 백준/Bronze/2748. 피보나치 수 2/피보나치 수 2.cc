#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[91];

void solve() {
	cin >> N;
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= N; i++) arr[i] = arr[i - 1] + arr[i - 2];
	cout << arr[N];
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}