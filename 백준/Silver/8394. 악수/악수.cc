#include <iostream>
using namespace std;

int table[10000000];
int n;

int main(void) {
	cin >> n;
	table[1] = 1;
	table[2] = 2;
	for (int i = 3; i <= n; i++) {
		table[i] += table[i - 2] + table[i - 1];
		table[i] %= 10;
	}
	cout << table[n];
	return 0;
}