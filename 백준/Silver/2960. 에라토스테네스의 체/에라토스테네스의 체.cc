#include <iostream>
using namespace std;

int N, K, cnt;
int table[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 2; i <= N; i++) {
		if (table[i] == 0) {
			for (int j = i; j <= N; j += i) {
				if (table[j] == 0) {
					table[j] = 1;
					cnt++;
					if (cnt == K) {
						cout << j;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}