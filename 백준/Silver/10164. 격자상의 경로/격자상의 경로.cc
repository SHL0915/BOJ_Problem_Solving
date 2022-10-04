#include <iostream>
using namespace std;

int N, M, K;
long long memo[16][16];

int main(void) {
	cin >> N >> M >> K;
	memo[1][1] = 1;
	if (K == 0) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (memo[i][j] == 0) memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
			}
		}
	}
	else {
		int K_x = ((K - 1) % M) + 1;
		int K_y = ((K - 1) / M) + 1;
		for (int i = 1; i <= K_y; i++) {
			for (int j = 1; j <= K_x; j++) {
				if (memo[i][j] == 0) memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
			}
		}
		for (int i = K_y; i <= N; i++) {
			for (int j = K_x; j <= M; j++) {
				if (memo[i][j] == 0) memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
			}
		}
	}	
	cout << memo[N][M];
	return 0;
}