#include <bits/stdc++.h>
using namespace std;

int N;
int arr[51];
int table[51][500001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	memset(table, -1, sizeof(table));
	table[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 500000; j++) {
			table[i][j] = max(table[i][j], table[i - 1][j]);
			if (j >= arr[i] && table[i - 1][j - arr[i]] != -1) table[i][j] = max(table[i][j], arr[i] + table[i - 1][j - arr[i]]);
			if (j + arr[i] <= 500000 && table[i - 1][j + arr[i]] != -1) table[i][j] = max(table[i][j], table[i - 1][j + arr[i]]);
			if (arr[i] >= j && table[i - 1][arr[i] - j] != -1) table[i][j] = max(table[i][j], table[i - 1][arr[i] - j] + j);
		}
	}
	if (table[N][0]) cout << table[N][0];
	else cout << -1;
	return 0;
}