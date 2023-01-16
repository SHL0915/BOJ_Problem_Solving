#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, S;
int arr[21];

void solve() {
	cin >> N >> S;
	int cnt = 0;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 1; i < (1 << N); i++) {
		int sum = 0;
		int bit = 1, idx = 0;
		while (bit <= i) {
			if (i & bit) sum += arr[idx];
			bit <<= 1;
			idx++;
		}
		if (sum == S) cnt++;
	}
	cout << cnt;
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