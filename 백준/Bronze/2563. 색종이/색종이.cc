#include <iostream>
using namespace std;

int N, cnt;
int paper[100][100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		for (int j = A; j < A + 10; j++) {
			for (int k = B; k < B + 10; k++) paper[j][k] = 1;
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j] == 1) cnt++;
		}
	}
	cout << cnt;
	return 0;
}