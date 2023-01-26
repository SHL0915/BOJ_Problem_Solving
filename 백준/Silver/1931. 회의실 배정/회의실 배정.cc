#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[100001];

bool cmp(pii A, pii B);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N, cmp);
	int now = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i].first >= now) {
			now = arr[i].second;
			ans++;
		}
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
	if (A.second == B.second) return A.first < B.first;
	return A.second < B.second;
}