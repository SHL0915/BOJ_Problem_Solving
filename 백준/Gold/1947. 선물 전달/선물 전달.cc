#include <iostream>
using namespace std;

int N;
long long table[1000001];

int main(void) {
	cin >> N;
	table[2] = 1;
	for (int i = 3; i <= N; i++) 
		table[i] = ((i - 1) * ((table[i - 1] + table[i - 2]) % 1000000000)) % 1000000000;
	cout << table[N];
	return 0;
}