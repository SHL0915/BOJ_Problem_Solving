#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[300000];
int delta[300000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 1; i < N; i++) delta[i] = arr[i] - arr[i - 1];
	sort(delta + 1, delta + N);
	long long ans = 0;
	for (int i = 1; i < N - K + 1; i++) ans += delta[i];
	cout << ans;
	return 0;
}