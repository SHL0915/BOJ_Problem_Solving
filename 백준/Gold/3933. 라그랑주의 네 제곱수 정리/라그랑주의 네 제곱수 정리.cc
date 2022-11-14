#include <iostream>
using namespace std;

const int MAX = 182;

int N;
long long table[(1 << 16)];

void BruteForce(int k, int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i <= MAX; i++) {
		for (int j = i; j <= MAX; j++) {
			for (int k = j; k <= MAX; k++) {
				for (int l = k; l <= MAX; l++) {
					long long A = i * i + j * j + k * k + l * l;
					if (A >= (1 << 16)) break;
					table[A]++;
				}
			}
		}
	}
	while (1) {
		cin >> N;
		if (N == 0) break;
		cout << table[N] << '\n';
	}
	return 0;
}