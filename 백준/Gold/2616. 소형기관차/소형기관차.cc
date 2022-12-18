#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[50001];
int psum[50001];
int table[50001][4];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	cin >> K;
	for (int i = K; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			int prev = i - K;
			table[i][j] = max(table[i - 1][j], table[prev][j - 1] + psum[i] - psum[prev]);
		}
	}
	cout << table[N][3];
	return 0;
}