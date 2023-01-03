#include <bits/stdc++.h>
using namespace std;

int N, ans;
pair<int, int> arr[1000000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	pair<int, int> now = arr[0];
	for (int i = 1; i < N; i++) {
		if (arr[i].first <= now.second) {
			now.first = min(now.first, arr[i].first);
			now.second = max(now.second, arr[i].second);
		}
		else {
			ans += (now.second - now.first);
			now = arr[i];
		}
	}
	ans += (now.second - now.first);
	cout << ans;
	return 0;
}