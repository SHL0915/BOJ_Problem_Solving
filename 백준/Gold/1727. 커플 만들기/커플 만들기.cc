#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, M;
int arr[1001];
int cmp[1001];
int table[1001][1001];

int absol(int A) {
	if (A < 0) return -A;
	else return A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	if (N > M) {
		for (int i = 1; i <= N; i++) cin >> cmp[i];
		for (int i = 1; i <= M; i++) cin >> arr[i];
		swap(N, M);
	}
	else {
		for (int i = 1; i <= N; i++) cin >> arr[i];
		for (int i = 1; i <= M; i++) cin >> cmp[i];
	}
	sort(arr + 1, arr + 1 + N);
	sort(cmp + 1, cmp + 1 + M);
	memset(table, INF, sizeof(table));
	table[0][0] = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			table[i][j] = min(table[i][j], table[i - 1][j]);
			if (j > 0) table[i][j] = min(table[i][j], table[i - 1][j - 1] + absol(cmp[i] - arr[j]));
		}
	}
	cout << table[M][N];
	return 0;
}