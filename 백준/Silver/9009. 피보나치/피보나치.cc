#include <iostream>
#include <queue>
using namespace std;

int fibo[45];
int T, n;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	fibo[0] = 1;
	fibo[1] = 1;
	for (int i = 2; i <= 43; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
	for (int i = 0; i < T; i++) {
		deque <int> result;
		cin >> n;
		int ptr = 43;
		while (1) {
			if (n == 0) break;
			for (int j = ptr; j >= 0; j--) {
				if (fibo[j] <= n) {
					ptr = j - 1;
					n -= fibo[j];
					result.push_front(fibo[j]);
				}
			}
		}
		for (int j = 0; j < result.size(); j++) cout << result[j] << " ";
		cout << '\n';
	}
}