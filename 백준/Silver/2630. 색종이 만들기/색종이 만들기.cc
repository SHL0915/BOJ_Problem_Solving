#include <iostream>
using namespace std;

int N, blue, white;
int paper[128][128];

void DnC(int x, int y, int n);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> paper[i][j];
	}
	DnC(0, 0, N);
	cout << white << "\n" << blue;
	return 0;
}

void DnC(int x, int y, int n) {	
	int sum = 0;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) sum += paper[i][j];
	}
	if (sum == 0) {
		white++;
		return;
	}
	else if (sum == n * n) {
		blue++;
		return;
	}
	else {
		DnC(x, y, n / 2);
		DnC(x + n / 2, y, n / 2);
		DnC(x, y + n / 2, n / 2);
		DnC(x + n / 2, y + n / 2, n / 2);
	}
}