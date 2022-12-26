#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[4];
int ans[4];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 4; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 3; i > 0; i--) {
		ans[i] = arr[i].second - arr[i].first;
		arr[i - 1].second += ans[i];
	}
	for (int i = 1; i < 4; i++) cout << ans[i] << '\n';
	return 0;
}