#include <iostream>
using namespace std;

int Cow[50000][2];
int line[3][2];

void BackTracking(int N, int ptr, int k);

int main(void) {
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> Cow[i][0] >> Cow[i][1];
	BackTracking(N, 0, 0);
	cout << 0;
	return 0;
}

void BackTracking(int N, int ptr, int k) {
	int i;
	if (k > 3) {
		return;
	}
	else if (ptr == N - 1) {
		for (i = 0; i < k; i++) {
			if (line[i][1] == 0) { // 세로 선
				if (Cow[ptr][0] == line[i][0]) {
					cout << 1;
					exit(0);
				}
			}
			else { // 가로 선
				if (Cow[ptr][1] == line[i][0]) {
					cout << 1;
					exit(0);
				}
			}
		}
	}
	else {
		for (i = 0; i < k; i++) {			
			if (line[i][1] == 0) { // 세로 선
				if (Cow[ptr][0] == line[i][0])
					BackTracking(N, ptr + 1, k);
			}
			else { // 가로 선
				if (Cow[ptr][1] == line[i][0])
					BackTracking(N, ptr + 1, k);
			}
		}
		if (k >= 3)
			return;
		line[k][0] = Cow[ptr][0];
		line[k][1] = 0;
		BackTracking(N, ptr + 1, k + 1);
		line[k][0] = Cow[ptr][1];
		line[k][1] = 1;
		BackTracking(N, ptr + 1, k + 1);
	}
}