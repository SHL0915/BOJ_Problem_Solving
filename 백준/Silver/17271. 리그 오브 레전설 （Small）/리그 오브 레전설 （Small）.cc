#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1000000007;

int N, M;
int table[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	table[0] = 1;
	for (int i = 1; i <= N; i++) {
		table[i] = table[i - 1];
		if (i >= M) {
			table[i] += table[i - M];
			table[i] %= mod;
		}
	}
	cout << table[N];
	return 0;
}