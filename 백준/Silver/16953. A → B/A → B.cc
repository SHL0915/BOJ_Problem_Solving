#include <iostream>
using namespace std;

long long A, B;
int ans;

void BackTracking(long long n, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B;
	BackTracking(A, 0);
	if (ans == 0) cout << -1;
	else cout << ans;
	return 0;
}

void BackTracking(long long n, int k) {
	if (n > B) return;
	else if (n == B) {
		if (ans == 0) ans = k + 1;
		else ans = min(ans, k + 1);
	}
	else {
		BackTracking(n * 2, k + 1);
		BackTracking(n * 10 + 1, k + 1);
	}
	return;
}