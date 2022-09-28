#include <iostream>
using namespace std;

int N, cnt = 0, strike, ball;
string question[100];
int answer[100][2];

int main(void) {
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> question[i];
		cin >> answer[i][0] >> answer[i][1];
	}
	for (i = 100; i <= 999; i++) {
		if ((i % 100) / 10 == 0 || i % 10 == 0)
			continue;
		if (i / 100 == (i % 100) / 10 || i / 100 == i % 10 || (i % 100) / 10 == i % 10)
			continue;		
		for (j = 0; j < N; j++) {
			strike = 0;
			ball = 0;
			if (i / 100 == question[j][0] - '0') strike++;
			else if (i / 100 == question[j][1] - '0' || i / 100 == question[j][2] - '0') ball++;
			if ((i % 100) / 10 == question[j][1] - '0') strike++;
			else if ((i % 100) / 10 == question[j][0] - '0' || (i % 100) / 10 == question[j][2] - '0') ball++;
			if (i % 10 == question[j][2] - '0') strike++;
			else if (i % 10 == question[j][0] - '0' || i % 10 == question[j][1] - '0') ball++;
			if (strike != answer[j][0] || ball != answer[j][1])
				break;
		}
		if (j == N) 
			cnt++;		
	}
	cout << cnt;
	return 0;	
}