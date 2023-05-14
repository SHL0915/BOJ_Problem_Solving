#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	int lptr = N / 2, rptr = N / 2;
	int cnt = 1;
	cout << arr[lptr] << " ";
	while (1) {
		if (cnt == N) break;
		cout << arr[--lptr] << " ";
		cnt++;
		if (cnt == N) break;
		cout << arr[++rptr] << " ";
		cnt++;
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