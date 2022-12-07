#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, K;
int arr[101];
int table[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	memset(table, INF, sizeof(table));
	for (int i = 1; i <= N; i++) cin >> arr[i];
	table[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j < arr[i]) continue;
			table[j] = min(table[j], table[j - arr[i]] + 1);
		}
	}
	if (table[K] == INF) cout << -1;
	else cout << table[K];
	return 0;
}