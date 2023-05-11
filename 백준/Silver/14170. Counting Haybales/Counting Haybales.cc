#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
int arr[100005];
vector <int> val;
ll psum[100005];

void solve() {
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		val.push_back(arr[i]);
	}

	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	
	for (int i = 0; i < N; i++) {
		int idx = lower_bound(val.begin(), val.end(), arr[i]) - val.begin() + 1;
		psum[idx]++;
	}

	for (int i = 1; i <= N; i++) psum[i] += psum[i - 1];

	for (int i = 0; i < Q; i++) {
		int l, r; cin >> l >> r;
		l = lower_bound(val.begin(), val.end(), l) - val.begin() + 1;
		r = upper_bound(val.begin(), val.end(), r) - val.begin();

		cout << psum[r] - psum[l - 1] << '\n';
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