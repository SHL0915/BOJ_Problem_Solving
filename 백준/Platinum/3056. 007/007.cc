#include <iostream>
using namespace std;

int N;
int arr[20][20];
double table[1 << 20];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(12);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}
	table[0] = 1;
	for (int i = 0; i < (1 << N); i++) {
		int bit = 1;
		int cnt = 0;
		while (bit <= i) {
			if (bit & i) cnt++;
			bit <<= 1;
		}
		for (int j = 0; j < N; j++) {
			if ((i & (1 << j)) == 0) table[i + (1 << j)] = max(table[i + (1 << j)], table[i] * ((double)arr[j][cnt] / 100.0));			
		}
	}
	cout << table[(1 << N) - 1] * 100;
	return 0;
}