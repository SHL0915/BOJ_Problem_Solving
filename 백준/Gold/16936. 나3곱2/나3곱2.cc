#include <iostream>
#include <algorithm>
using namespace std;

long long N;
long long B[100];
long long A[100];
long long mark[100];

void BackTracking(long long n, long long k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> B[i];
	sort(B, B + N);
	for (int i = 0; i < N; i++) {
		mark[i] = 1;
		BackTracking(B[i], 0);
		mark[i] = 0;
	}
	return 0;
}

void BackTracking(long long n, long long k) {
	A[k] = n;
	if (k == N - 1) {
		for (int i = 0; i < N; i++) cout << A[i] << ' ';
		exit(0);
	}
	else {
		long long idx = lower_bound(B, B + N, n * 2) - B;
		if (binary_search(B, B + N, n * 2) && mark[idx] == 0) {
			mark[idx] = 1;
			BackTracking(n * 2, k + 1);
			mark[idx] = 0;
		}
		if (n % 3 == 0) {
			idx = lower_bound(B, B + N, n / 3) - B;
			if (binary_search(B, B + N, n / 3) && mark[idx] == 0) {
				mark[idx] = 1;
				BackTracking(n / 3, k + 1);
				mark[idx] = 0;
			}
		}
	}
}