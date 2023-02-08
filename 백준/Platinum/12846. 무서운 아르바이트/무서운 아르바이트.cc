#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[100005];

ll DnC(int left, int right);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	cout << DnC(1, N);
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

ll DnC(int left, int right) {
	if (left > right) return 0;
	if (left == right) return arr[left];
	ll ret = 0;
	int mid = (left + right) / 2;
	ret = max(ret, DnC(left, mid - 1));
	ret = max(ret, DnC(mid + 1, right));
	ll h = arr[mid], l = mid, r = mid, w = 1;
	while (l >= left && r <= right) {
		h = min({ h, arr[l], arr[r] });
		ret = max(ret, h * w);
		if (l == left) {
			r++;
			w++;
		}
		else if (r == right) {
			l--;
			w--;
		}
		else if (arr[l - 1] >= arr[r + 1]) {
			l--;
			w++;
		}
		else {
			r++;
			w++;
		}
	}
	return ret;
}