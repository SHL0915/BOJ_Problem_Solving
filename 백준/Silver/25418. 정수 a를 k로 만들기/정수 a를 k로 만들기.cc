#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int A, K;
int table[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> K;
	memset(table, INF, sizeof(table));
	table[A] = 0;
	for (int i = A; i <= K; i++) {
		table[i] = min(table[i], table[i - 1] + 1);
		if (i % 2 == 0) table[i] = min(table[i], table[i / 2] + 1);
	}
	cout << table[K];
	return 0;
}