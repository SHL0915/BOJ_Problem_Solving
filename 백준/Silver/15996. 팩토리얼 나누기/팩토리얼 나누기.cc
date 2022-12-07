#include <bits/stdc++.h>
using namespace std;

long long N, A, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> A;
	long long x = A;
	while (x <= N) {
		ans += N / x;
		x *= A;
	}
	cout << ans;
	return 0;
}