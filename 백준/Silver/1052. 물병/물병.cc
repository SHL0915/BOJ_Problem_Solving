#include <iostream>
using namespace std;

int N, K;

int main(void) {
	cin >> N >> K;
	for (int i = N; ; i++) {
		int bit = 1;
		int cnt = 0;
		while (1) {
			if (bit > i) break;
			if (bit & i) cnt ++;
			bit <<= 1;
		}
		if (cnt <= K) {
			cout << i - N;
			return 0;
		}
	}
}