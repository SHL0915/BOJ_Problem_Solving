#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int L[20];
int J[20];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> L[i];
	for (int i = 0; i < N; i++) cin >> J[i];
	for (int i = 0; i < (1 << N); i++) {
		int Lsum = 0, Jsum = 0;
		int bit = 1, idx = 0;
		while (bit <= i) {
			if (bit & i) {
				Lsum += L[idx];
				Jsum += J[idx];
			}
			idx++;
			bit <<= 1;
		}
		if (Lsum < 100) ans = max(ans, Jsum);
	}
	cout << ans;
	return 0;
}