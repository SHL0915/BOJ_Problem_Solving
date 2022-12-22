#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
pair<int, int> arr[20];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 0; i < (1 << M); i++) {
		int bit = 1;
		int page = 0;
		int day = 0;
		int cnt = 0;
		while (bit <= i) {
			if (bit & i) {
				day += arr[cnt].first;
				page += arr[cnt].second;
			}
			bit <<= 1;
			cnt++;
		}
		if (day > N) continue;
		else ans = max(ans, page);
	}
	cout << ans;
	return 0;
}