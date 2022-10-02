#include <iostream>
using namespace std;

int N, num = 0;
int row[14];
int rightUpper[28];
int leftUpper[28];

void N_Queen(int k);

int main(void) {
	cin >> N;
	N_Queen(0);
	cout << num;
	return 0;
}

void N_Queen(int k) {
	if (k == N) {
		num++;
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (row[i] == 0 && rightUpper[i + k] == 0 && leftUpper[N - 1 + k - i] == 0) {
				row[i] = 1;
				rightUpper[i + k] = 1;
				leftUpper[N - 1 + k - i] = 1;
				N_Queen(k + 1);
				row[i] = 0;
				rightUpper[i + k] = 0;
				leftUpper[N - 1 + k - i] = 0;
			}
		}
	}
}