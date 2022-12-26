#include <bits/stdc++.h>
using namespace std;

int N, K;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	int ans = 1;
	for (int i = 2; i <= N; i++) ans = (ans + K - 1) % i + 1;
	cout << ans;
	return 0;
}