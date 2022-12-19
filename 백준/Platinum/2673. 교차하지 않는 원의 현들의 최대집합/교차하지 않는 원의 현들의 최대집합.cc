#include <bits/stdc++.h>
using namespace std;

int N;
int arr[101][101];
int table[101][101];

int DP(int start, int end);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		arr[min(A, B)][max(A, B)] = 1;
	}
	memset(table, -1, sizeof(table));
	cout << DP(1, 100);
	return 0;
}

int DP(int start, int end) {
	if (start >= end) return 0;
	int& ret = table[start][end];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = start; i <= end; i++) {
		for (int j = i + 1; j <= end; j++) {
			if (arr[i][j] == 1) {
				ret = max(ret, 1 + DP(i + 1, j - 1) + DP(j + 1, end));
			}
		}
	}
	return ret;
}