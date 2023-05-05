#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[100005];
ll K, ans;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> K;
	
	ll cnt = 0, val = 0;
	for (int i = 0; i < N - 1; i++) if (arr[i] > arr[i + 1]) val = max(val, arr[i]);
	for (int i = 0; i < N; i++) {
		if (arr[i] >= val) continue;
		cnt += val - arr[i];
		arr[i] = val;
	}

	if (cnt) {
		if (K < cnt) {
			cout << 0;
			return;
		}
		K -= cnt;
		ans++;
	}
	
	vector <int> idx;
	idx.push_back(0);
	for (int i = 1; i < N; i++) if (arr[i] != arr[i - 1]) idx.push_back(i);

	for (int i = 1; i < idx.size(); i++) {
		cnt = min(arr[idx[i]] - arr[idx[i - 1]], K / idx[i]) * idx[i];
		ans += min(arr[idx[i]] - arr[idx[i - 1]], K / idx[i]);
		K -= cnt;
	}

	ans += K / N;

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