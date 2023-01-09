#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int table[31][100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) table[0][i] = i;	
	for (int i = 0; i < M; i++) {
		int L, R;
		cin >> L >> R;
		for (int j = L; j <= (R + L) / 2; j++) swap(table[0][j], table[0][R + L - j]);
	}
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= N; j++) table[i][j] = table[i - 1][table[i - 1][j]];
	}
	for (int i = 1; i <= N; i++) {
		int now = i;
		long long bit = 1;
		int pos = 0;
		while (bit <= K) {
			if (bit & K) now = table[pos][now];
			pos++;
			bit <<= 1;
		}
		cout << now << '\n';
	}
	return 0;
}