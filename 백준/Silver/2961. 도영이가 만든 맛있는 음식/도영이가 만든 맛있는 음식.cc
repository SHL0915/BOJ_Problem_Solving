#include <iostream>
using namespace std;

const int INF = 1234567890;

int N, ans = INF;
int ingredient[10][2];

int absol(int A) {
	if (A >= 0) return A;
	else return -1 * A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> ingredient[i][0] >> ingredient[i][1];
	for (int i = 1; i < (1 << N); i++) {
		int bit = 1, idx = 0;
		int A = 1, B = 0;
		while (bit <= i) {
			if (bit & i) {
				A *= ingredient[idx][0];
				B += ingredient[idx][1];
			}
			bit <<= 1;
			idx++;
		}
		ans = min(ans, absol(B - A));
	}
	cout << ans;
	return 0;
}