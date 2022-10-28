#include <iostream>
using namespace std;

int N, M;
int wage[100000];
long long psum[100000];
long long ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> wage[i];
	for (int i = 0; i < N; i++) {
		if (i == 0) psum[i] = wage[i];
		else psum[i] = psum[i - 1] + wage[i];
	}
	for (int i = M - 1; i < N; i++) ans = max(ans, psum[i] - psum[i - M + 1] + wage[i - M + 1]);
	cout << ans;
	return 0;
}