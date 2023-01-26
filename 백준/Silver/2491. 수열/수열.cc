#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, ans;
int arr[100001];
int A[100001], B[100001];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) {
		A[i] = 1, B[i] = 1;
		if (i) {
			if (arr[i] >= arr[i - 1]) A[i] = max(A[i], A[i - 1] + 1);
			if (arr[i] <= arr[i - 1]) B[i] = max(B[i], B[i - 1] + 1);
		}
		ans = max({ ans, A[i], B[i] });
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