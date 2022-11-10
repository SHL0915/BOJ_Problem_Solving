#include <iostream>
#include <algorithm>
using namespace std;

int N, tc;
int val[400][800];
int psum[400][800];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (++tc) {
		int ans = -1000;
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 2 * i + 1; j++) {
				cin >> val[i][j];
				if (j == 0) psum[i][j] = val[i][j];
				else psum[i][j] = psum[i][j - 1] + val[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 2 * i + 1; j++) {
				if (j % 2 == 1) continue;
				int sum = 0;
				for (int l = 0; l < N - i; l++) {
					sum += (psum[i + l][j + 2 * l] - psum[i + l][j] + val[i + l][j]);
					ans = max(ans, sum);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 2 * i + 1; j++) {
				if (j % 2 == 0) continue;
				int sum = 0;
				for (int l = 0; l <= i; l++) {
					if (j > 2 * (i - l)) break;
					if (j - 2 * l < 0) break;
					sum += (psum[i - l][j] - psum[i - l][j - 2 * l] + val[i - l][j - 2 * l]);
					ans = max(ans, sum);
				}
			}
		}
		cout << tc << ". " << ans << '\n';
	}
	return 0;
}