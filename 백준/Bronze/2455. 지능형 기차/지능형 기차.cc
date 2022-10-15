#include <iostream>
using namespace std;

int ans, train;

int main(void) {
	for (int i = 0; i < 4; i++) {
		int A, B;
		cin >> A >> B;
		train += (B - A);
		ans = max(ans, train);
	}
	cout << ans;
	return 0;
}