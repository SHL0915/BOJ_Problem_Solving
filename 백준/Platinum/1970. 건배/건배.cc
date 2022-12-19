#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1001];
int table[1001][1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N - 1; i++) if (arr[i] == arr[i + 1]) table[i][i + 1] = 1;
	for (int k = 2; k < N; k++) {
		for (int i = 0; i < N - k; i++) {
			if (arr[i] == arr[i + k]) table[i][i + k] = table[i + 1][i + k - 1] + 1;
			for (int j = 0; j < k; j++) {
				table[i][i + k] = max(table[i][i + k], table[i][i + j] + table[i + j + 1][i + k]);
			}
		}
	}
	cout << table[0][N - 1];
	return 0;
}