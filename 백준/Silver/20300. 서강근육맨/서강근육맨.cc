#include <iostream>
#include <algorithm>
using namespace std;

int N, lptr, rptr;
long long ans;
long long arr[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	if (N % 2 == 0) {
		ans = arr[0] + arr[N - 1];
		lptr = 1;
	}
	else {
		ans = arr[N - 1];
		lptr = 0;
	}	
	rptr = N - 2;
	while (lptr < rptr) {
		ans = max(ans, arr[lptr] + arr[rptr]);
		lptr++;
		rptr--;
	}
	cout << ans;
	return 0;
}