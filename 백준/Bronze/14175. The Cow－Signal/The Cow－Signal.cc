#include <bits/stdc++.h>
using namespace std;

int M, N, K;
string paper[11];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N >> K;
	for (int i = 0; i < M; i++) cin >> paper[i];
	for (int i = 0; i < M; i++) {
		for (int a = 0; a < K; a++) {
			for (int j = 0; j < N; j++) {
				for (int b = 0; b < K; b++) cout << paper[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}