#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll D, N, M, K;

void solve() {
	cin >> D >> N >> M >> K;

	ll a = D - N % D, b = D - M % D;
	if (a > b) swap(a, b);

	vector <pii> arr;

	arr.push_back({ K / D, K });
	if(K >= a) arr.push_back({ (K - a) / D + 1, K - a });
	if(K >= b) arr.push_back({ (K - b) / D + 1, K - b });
	if (K >= a + b) arr.push_back({ (K - a - b) / D + 2, K - a - b });

	sort(arr.begin(), arr.end());
	cout << arr.back().second;
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