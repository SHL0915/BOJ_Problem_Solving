#include <iostream>
using namespace std;

const long long BIG_NUM = 1000000001;

int N, M, i;
long long K;
long long memo[201][201];

long long DP(int N, int M);

int main(void) {
	cin >> N >> M >> K;
	if (K > DP(N, M)) {
		cout << -1;
		return 0;
	}
	while (1) {
		if (N == 0) {
			for (int i = 0; i < M; i++)
				cout << 'z';
			break;
		}
		else if (M == 0) {
			for (int i = 0; i < N; i++)
				cout << 'a';
			break;
		}
		if (K > DP(N - 1, M)) {
			cout << 'z';
			K -= DP(N - 1, M);
			M--;
		}
		else if (K == DP(N - 1, M)) {
			cout << 'a';
			for (int j = 0; j < M; j++)
				cout << 'z';
			for (int j = 0; j < N - 1; j++)
				cout << 'a';
			break;
		}
		else {
			cout << 'a';			
			N--;
		}
	}
}

long long DP(int N, int M) {
	if (N == 0 && M == 0) return 0;
	else if (memo[N][M] != 0) return memo[N][M];
	else if (N == 0 || M == 0) memo[N][M] = 1;
	else {
		memo[N][M] += DP(N, M - 1) + DP(N - 1, M);
		if (memo[N][M] >= BIG_NUM) memo[N][M] = BIG_NUM;		
	}
	return memo[N][M];
}