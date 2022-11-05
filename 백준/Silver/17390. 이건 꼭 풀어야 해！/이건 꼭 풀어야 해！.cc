#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, Q;
long long arr[300000];
long long psum[300000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		if (i == 0) psum[i] = arr[i];
		else psum[i] = psum[i - 1] + arr[i];
	}
	for (int i = 0; i < Q; i++) {
		int L, R;
		cin >> L >> R;
		cout << psum[R - 1] - psum[L - 1] + arr[L - 1] << '\n';
	}
	return 0;
}