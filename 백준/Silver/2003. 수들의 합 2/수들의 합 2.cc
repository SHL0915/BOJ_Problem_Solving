#include <iostream>
#include <algorithm>
using namespace std;

long long N, M;
long long arr[10000];
long long psum[10000];
long long cnt;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] == M) cnt++;
		if (i == 0) psum[i] = arr[i];
		else psum[i] = psum[i - 1] + arr[i];
	}
	for (int i = 0; i < N - 1; i++) {
		if (binary_search(psum + i + 1, psum + N, M + psum[i] - arr[i])) cnt++;
	}
	cout << cnt;
	return 0;
}