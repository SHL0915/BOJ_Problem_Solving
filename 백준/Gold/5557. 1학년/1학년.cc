#include <bits/stdc++.h>
using namespace std;

int N;
int arr[101];
long long table[101][21];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	table[1][arr[1]] = 1;
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j - arr[i] >= 0) table[i][j] += table[i - 1][j - arr[i]];
			if (j + arr[i] <= 20) table[i][j] += table[i - 1][j + arr[i]];
		}
	}
	cout << table[N - 1][arr[N]];
	return 0;
}