#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, L;
int arr[55];
int delt[55];

int BinarySearch(int left, int right);

void solve() {
	cin >> N >> M >> L;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	arr[N + 1] = L;
	for (int i = 0; i <= N; i++) delt[i] = arr[i + 1] - arr[i];	
	int ans = BinarySearch(1, L);
	int cnt = 0;
	for (int i = 0; i <= N; i++) cnt += (delt[i] - 1) / ans;
	if (cnt <= M) cout << ans;
	else cout << ans + 1;
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

int BinarySearch(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i <= N; i++) cnt += (delt[i] - 1) / mid;		
		if (cnt <= M) return BinarySearch(left, mid - 1);
		else return BinarySearch(mid + 1, right);
	}
	else return left;
}