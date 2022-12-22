#include <bits/stdc++.h>
using namespace std;

int N, ans, extra;
pair <int, int> arr[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].second >> arr[i].first;
	sort(arr, arr + N);
	ans = arr[0].first - arr[0].second;
	for (int i = 1; i < N; i++) {
		extra += (arr[i].first - arr[i - 1].first);
		if (extra >= arr[i].second) {
			extra -= arr[i].second;
			arr[i].second = 0;
		}
		else {
			arr[i].second -= extra;
			extra = 0;
		}
		ans -= arr[i].second;
	}
	cout << ans;
	return 0;
}