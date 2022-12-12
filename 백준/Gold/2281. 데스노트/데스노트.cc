#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
int arr[1001];
long long table[1001][1005];
long long ans = INF;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];			
	memset(table, INF, sizeof(table));
	table[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (table[i - 1][j] == INF) continue;
			table[i][arr[i]] = min(table[i][arr[i]], table[i - 1][j] + (M - j) * (M - j));
			if (arr[i] + j + 1 <= M) {
				if (j != 0) table[i][j + arr[i] + 1] = min(table[i][j + arr[i] + 1], table[i - 1][j]);
				else table[i][j + arr[i]] = min(table[i][j + arr[i]], table[i - 1][j]);
			}
		}
	}
	for (int i = 0; i <= M; i++) ans = min(ans, table[N][i]);	
	cout << ans;
	return 0;
}