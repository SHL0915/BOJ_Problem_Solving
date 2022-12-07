#include <bits/stdc++.h>
using namespace std;

int N;
long long table[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	table[1] = 1;
	for (int i = 2; i <= N; i++) {
		table[i] = max(table[i], table[i - 1] + 1);
		for (int j = i - 3; j >= 0; j--) table[i] = max(table[i], table[j] * (i - j - 1));
	}
	cout << table[N];
	return 0;
}