#include <iostream>
using namespace std;

int N, ans;

void DNQ(int n);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	DNQ(N);
	cout << ans;
	return 0;
}

void DNQ(int n) {
	if (n == 1) return;
	else {
		ans += (n / 2 * (n - n / 2));
		DNQ(n / 2);
		DNQ(n - n / 2);
	}
	return;
}