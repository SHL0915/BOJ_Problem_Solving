#include <iostream>
using namespace std;

int N;
long long table[31][31];

// H 문자가 들어갈 수 있는 자리는 N 자리, 각 자리까지의 H의 개수의 합은 index를 초과할 수 없다.

int main(void) {
	while (1) {
		cin >> N;
		if (N == 0) break;	
		for (int i = 0; i <= N; i++) 
			for (int j = 0; j <= N; j++)
				table[i][j] = 0;		
		table[1][1] = 1;
		table[1][0] = 1;
		for (int i = 2; i <= N; i++) { // 현재 i번째 단계
			for (int j = 0; j <= i; j++) { // 현재까지 총 j개의 H문자가 삽입되는 경우를 수집
				table[i][j] = 0;
				for (int k = 0; k <= j; k++) { // 현재 단계에서 k개의 H문자가 삽입
					table[i][j] += table[i - 1][j - k];
				}
			}
		}
		cout << table[N][N] << "\n";
	}
}