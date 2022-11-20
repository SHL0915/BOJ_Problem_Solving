#include <iostream>
using namespace std;

int N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	if (N == 1) cout << 0;
	else {
		if (N % 2 == 0) cout << (N * N) / 2;
		else cout << (N * N - 1) / 2 + 1;
	}
	return 0;
}