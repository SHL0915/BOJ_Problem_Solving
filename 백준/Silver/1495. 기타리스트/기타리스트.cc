#include <bits/stdc++.h>
using namespace std;

int N, S, M, ans = -1;
int arr[51];
int table[51][1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	table[0][S] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (j - arr[i] >= 0) {
				if (table[i - 1][j - arr[i]] == 1) table[i][j] = 1;
			}
			if (j + arr[i] <= M) {
				if (table[i - 1][j + arr[i]] == 1) table[i][j] = 1;
			}
		}
	}
	for (int i = 0; i <= M; i++) if (table[N][i] == 1) ans = i;
	cout << ans;
	return 0;
}