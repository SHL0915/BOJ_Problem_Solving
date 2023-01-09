#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int table[100001][31];
int ans[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) table[i][0] = i;	
	for (int i = 0; i < M; i++) {
		int L, R;
		cin >> L >> R;
		for (int j = L; j <= (R + L) / 2; j++) swap(table[j][0], table[R + L - j][0]);
	}
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= N; j++) table[j][i] = table[table[j][i - 1]][i - 1];
	}
	for (int i = 1; i <= N; i++) {
		int now = i;
		long long bit = 1;
		int pos = 0;
		while (bit <= K) {
			if (bit & K) now = table[now][pos];
			pos++;
			bit <<= 1;
		}
		cout << now << '\n';
	}
	return 0;
}