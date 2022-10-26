#include <iostream>
using namespace std;

const long long mod = 1000000007;

int N;
long long table[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	table[1] = 1;
	for (int i = 2; i <= 1000000; i++) table[i] = (table[i - 1] + table[i - 2]) % mod;
	cin >> N;
	cout << table[N];
	return 0;
}