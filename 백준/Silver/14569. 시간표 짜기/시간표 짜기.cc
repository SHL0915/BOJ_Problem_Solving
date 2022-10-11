#include <iostream>
using namespace std;

int N, M;
int classes[1000][50];

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k, t;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> t;
			classes[i][t - 1] = 1;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int student[50] = { 0 };
		int p, q, cnt = 0;
		cin >> p;
		for (int j = 0; j < p; j++) {
			cin >> q;
			student[q - 1] = 1;
		}
		for (int j = 0; j < N; j++) {
			int k;
			for (k = 0; k < 50; k++) if (classes[j][k] == 1 && student[k] == 0) break;
			if (k == 50) cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}