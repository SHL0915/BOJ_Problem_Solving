#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N;
vector <ll> arr;

void solve() {
	cin >> N;
	ll base = 1;
	ll sum = 0, ans = 0;
	while (N) {
		arr.push_back(N % 10);
		sum += base;
		base *= 10;
		N /= 10;
	}

	for (int i = 0; i < arr.size(); i++) ans += sum * arr[i];
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