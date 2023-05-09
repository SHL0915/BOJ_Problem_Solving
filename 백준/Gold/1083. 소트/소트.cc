#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, S;
int arr[55];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> S;

	for (int i = 0; i < N; i++) {
		int max_val = -1, idx = -1;
		for (int j = 0; j <= S && i + j < N; j++) {
			if (arr[i + j] > max_val) {
				max_val = arr[i + j];
				idx = i + j;
			}
		}
		
		if (idx == i) continue;
		for (int j = idx - 1; j >= i; j--) {
			swap(arr[j], arr[j + 1]);
			S--;
		}
	}

	for (int i = 0; i < N; i++) cout << arr[i] << " ";
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