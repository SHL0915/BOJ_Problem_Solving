#include <iostream>
using namespace std;

int N, M, cnt;
int cube[102][102];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> cube[i][j];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cnt += 2;
			for (int k = cube[i][j]; k >= 1; k--) {
				if (cube[i - 1][j] < k) cnt++;
				if (cube[i + 1][j] < k) cnt++;
				if (cube[i][j - 1] < k) cnt++;
				if (cube[i][j + 1] < k) cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}