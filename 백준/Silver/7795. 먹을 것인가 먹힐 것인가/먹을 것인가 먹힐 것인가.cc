#include <iostream>
#include <algorithm>
using namespace std;

int T, N, M;
int A[20000];
int B[20000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		int ans = 0;
		cin >> N >> M;
		for (int j = 0; j < N; j++) cin >> A[j];
		for (int j = 0; j < M; j++) cin >> B[j];
		sort(B, B + M);
		for (int j = 0; j < N; j++) ans += (lower_bound(B, B + M, A[j]) - B);
		cout << ans << "\n";
	}
	return 0;
}