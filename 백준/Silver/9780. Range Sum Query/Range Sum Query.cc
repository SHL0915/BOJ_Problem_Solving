#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
ll arr[100001];

void solve() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		a++; b++;
		cout << arr[b] - arr[a - 1] << '\n';
	}
	cout << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}