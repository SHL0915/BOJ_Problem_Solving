#include <iostream>
#include <memory.h>
using namespace std;

int N, K, A, ans;
int mark[100200];
int table[100200][2];

int DP(int now, int type);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	while (cin >> A) mark[A] = 1;	
	if (K >= N) {
		for (int i = 1; i <= N; i++) {
			if (mark[i] == 0) {
				cout << 1;
				return 0;
			}
		}
		cout << 0;
		return 0;
	}
	memset(table, -1, sizeof(table));
	for (int i = 1; i <= K; i++) {
		if (mark[i] == 0) {
			ans |= DP(i, 0);
		}
	}
	cout << ans;	
	return 0;
}

int DP(int now, int type) {
	if (table[now][type] != -1) return table[now][type];
	table[now][type] = 1;
	int temp = 0;
	for (int i = now + 1; i <= min(N, now + K); i++) {
		if (mark[i] == 0) {
			temp |= DP(i, (type ^ 1));
		}
	}
	table[now][type] ^= temp;
	return table[now][type];
}