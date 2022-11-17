#include <iostream>
using namespace std;

int N, K, a_num, b_num;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	if (N % 2 == 0 && K > (N/2)*(N/2)) {
		cout << -1;
		return 0;
	}
	else if (N % 2 == 1 && K > (N/2)* (N - N/2)) {
		cout << -1;
		return 0;
	}
	for (b_num = N - 1; b_num >= 0; b_num--) {
		if (b_num * (N - b_num) >= K) break;
	}
	a_num = N - b_num;
	string ans = "";
	for (int i = 0; i < N; i++) {
		if (K >= b_num) {
			ans += 'A';
			a_num--;
			K -= b_num;
		}
		else {
			ans += 'B';
			b_num--;
		}
	}
	cout << ans;
	return 0;
}