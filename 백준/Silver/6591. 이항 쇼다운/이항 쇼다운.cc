#include <iostream>
#include <algorithm>
using namespace std;

int N, K;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> N >> K;
		if (N == 0 && K == 0) break;
		K = min(K, N - K);
		long long result = 1;
		for (int i = 1, j = N; i <= K; i++, j--) {
			result *= j;
			result /= i;
		}
		cout << result << '\n';
	}
	return 0;
}