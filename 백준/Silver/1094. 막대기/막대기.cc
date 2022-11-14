#include <iostream>
#include <bit>
#include <bitset>
using namespace std;

unsigned int X;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> X;
	cout << popcount(X);
	return 0;
}