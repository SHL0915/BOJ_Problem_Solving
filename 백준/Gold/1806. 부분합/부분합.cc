#include <iostream>
using namespace std;

int N, lptr, rptr, ans = 100001;
long long arr[100000];
long long psum[100000];
long long S;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] >= S) {
			cout << 1;
			return 0;
		}
		if (i == 0) psum[i] = arr[i];
		else psum[i] = psum[i - 1] + arr[i];
	}
	lptr = N - 1;
	for (rptr = N - 1; rptr >= 0; rptr--) {
		if (lptr == 0 && psum[rptr] < S) break;
		while (lptr >= 0) {
			if (psum[rptr] - psum[lptr] + arr[lptr] >= S) break;
			else lptr--;
		}
		if (psum[rptr] - psum[lptr] + arr[lptr] >= S) ans = min(ans, rptr - lptr + 1);
		else break;
	}
	if (ans == 100001) cout << 0;
	else cout << ans;
	return 0;
}