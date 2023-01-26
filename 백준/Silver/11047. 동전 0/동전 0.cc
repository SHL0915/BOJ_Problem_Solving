#include <iostream>
using namespace std;

int N, K, ans;
int coins[10];

int main(void) {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> coins[i];
	for (int i = N - 1; i >= 0; i--) {
		if (K < coins[i]) continue;
		else {
			ans += K / coins[i];
			K %= coins[i];
		}
	}
	cout << ans;
	return 0;
}