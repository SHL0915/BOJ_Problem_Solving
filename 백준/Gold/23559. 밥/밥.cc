#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, X;
ll ans;
pii arr[100001];

bool cmp(pii A, pii B);

void solve() {
	cin >> N >> X;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N, cmp);
	int cnt = (X - 1000 * N) / 4000;
	for (int i = 0; i < N; i++) {
		if (i < cnt) ans += max(arr[i].first, arr[i].second);
		else ans += arr[i].second;
	}
	cout << ans;
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

bool cmp(pii A, pii B) {
	return A.first - A.second > B.first - B.second;
}