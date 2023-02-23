#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[100001];
ll psum[100001];

ll DNC(int left, int right);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	cout << DNC(1, N);
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

ll DNC(int left, int right) {
	if (left > right) return 0;
	ll ret = 0;
	int mid = (left + right) / 2;
	ret = max(ret, DNC(left, mid - 1));
	ret = max(ret, DNC(mid + 1, right));
	ll l = mid, r = mid, val = arr[mid];
	while (1) {
		val = min({ val, arr[l], arr[r] });
		ret = max(ret, (psum[r] - psum[l - 1]) * val);
		if (l == left && r == right) break;
		if (l == left) r++;
		else if (r == right) l--;
		else {
			if (arr[l - 1] > arr[r + 1]) l--;
			else r++;
		}
	}
	return ret;
}