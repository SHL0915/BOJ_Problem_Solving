#include <iostream>
using namespace std;

const long long mod = 1000000007;

int N;
long long table[1000001];
long long extra[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	table[0] = 1;
	table[1] = 2;
	table[2] = 7;
	extra[0] = 1;
	extra[1] = 3;
	extra[2] = 10;
	for (int i = 3; i <= N; i++) {
		table[i] = ((table[i - 1] * 2) % mod + (table[i - 2] * 3) % mod + (extra[i - 3] * 2) % mod) % mod;
		extra[i] = (extra[i - 1] + table[i]) % mod;
	}
	cout << table[N];
	return 0;
}