#include <iostream>
using namespace std;

int N, M;
int numbers[2000];
int table[2000][2000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> numbers[i];
	for (int i = 0; i < N; i++) { // 길이가 홀수, 중심이 i인 회문 문자를 저장		
		int j = 0, flag = 0;
		while (1) {
			if (i - j < 0 || i + j >= N) break;		
			else {
				if (flag == 0) {
					if (numbers[i - j] == numbers[i + j]) table[i - j][i + j] = 1;
					else {
						table[i - j][i + j] = -1;
						flag = 1;
					}
				}
				else table[i - j][i + j] = -1;
			}
			j++;
		}
	}
	for (int i = 0; i < N; i++) { // 길이가 짝수, 중심이 i인 회문 문자를 저장		
		int j = 1, flag = 0;
		while (1) {
			if (i - j + 1 < 0 || i + j >= N) break;
			else {
				if (flag == 0) {
					if (numbers[i - j + 1] == numbers[i + j]) table[i - j + 1][i + j] = 1;
					else {
						table[i - j + 1][i + j] = -1;
						flag = 1;
					}
				}
				else table[i - j + 1][i + j] = -1;
			}
			j++;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		if (table[S - 1][E - 1] == 1) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}