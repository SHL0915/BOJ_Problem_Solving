#include <iostream>
using namespace std;

long long N, temp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	temp = 1;
	for (int i = 1; i <= N; i++) {
		temp *= i;
		temp %= 100000000;
		while (temp % 10 == 0) temp /= 10;
	}
	cout << temp % 10;
	return 0;
}