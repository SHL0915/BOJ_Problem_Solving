#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, ans = INF;
int arr[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if (j == i) continue;
			if (j > i) sum += arr[j] * (j - i);
			else sum += arr[j] * (N - i + j);
		}
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}