#include <iostream>
using namespace std;

int N, M;
long long classes[1000];
long long student;

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		long long bit = 1, t;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> t;
			classes[i] += (bit << (t - 1));
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		student = 0;
		int p, cnt = 0;
		long long bit = 1, q;
		cin >> p;
		for (int j = 0; j < p; j++) {
			cin >> q;
			student += (bit << (q - 1));
		}
		for (int j = 0; j < N; j++) {
			bit = 1;
			for (int k = 0; k < 50; k++) {
				if ((bit & classes[j]) && (bit & student) == 0) break;
				bit <<= 1;
				if (k == 49) cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}