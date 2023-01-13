#include <bits/stdc++.h>
using namespace std;

unsigned long long N, cnt = 64;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;	
	while (N) {
		if (N & 1) {
			cout << cnt;
			return 0;
		}
		N >>= 1;
		cnt--;
	}
	return 0;
}