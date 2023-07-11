#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[1000005];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		arr[a]++;
	}

	int ans = 0;
	for (int i = 0; i <= 1000000; i++) {
		if (arr[i] % 2) ans++;
		arr[i + 1] += arr[i] / 2;
	}

	if (N == 1) cout << "N";
	else {
		if (ans <= 2) cout << "Y";
		else cout << "N";
	}

	return;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
