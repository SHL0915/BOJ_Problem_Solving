#include <bits/stdc++.h>
using namespace std;

unsigned long long N, temp = 1;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	temp <<= 63;
	N = (__int128)temp * 2 - N;
	int cnt = 0;
	while (N) {
		cnt++;
		N /= 2;
	}
	cout << 64 - cnt + 1;
	return 0;
}