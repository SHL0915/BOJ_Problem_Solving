#include <bits/stdc++.h>
using namespace std;

int N, K, m, cnt, ans;
int arr[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		m = arr[i];
		cnt = 1;
		for (int j = i + 1; j < N; j++) {
			if (arr[j] - m <= K) cnt++;
			else {
				cnt = 1;
				m = arr[j];
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans;
	return 0;
}