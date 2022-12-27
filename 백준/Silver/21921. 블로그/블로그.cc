#include <bits/stdc++.h>
using namespace std;

int N, X, cnt, ans;
long long arr[250001];
long long psum[250001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> X;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	for (int i = X; i <= N; i++) {
		if (psum[i] - psum[i - X] == ans) cnt++;
		else if (psum[i] - psum[i - X] > ans) {
			ans = psum[i] - psum[i - X];
			cnt = 1;
		}
	}
	if (ans == 0) cout << "SAD";
	else cout << ans << '\n' << cnt;
	return 0;
}