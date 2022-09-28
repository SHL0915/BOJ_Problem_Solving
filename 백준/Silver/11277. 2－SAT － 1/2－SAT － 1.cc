#include <iostream>
using namespace std;

int N, M;
int function[100][2];
int variable[20];

void ChooseVariable(int k);
void Judge(int k);

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> function[i][0] >> function[i][1];
	}
	ChooseVariable(0);
	cout << 0;
	return 0;
}

void ChooseVariable(int k) {
	if (k == N) {
		Judge(0);
	}
	else {
		for (int i = 0; i < 2; i++) {
			variable[k] = i;
			ChooseVariable(k + 1);
		}
	}
}

void Judge(int k) {
	int A, B;
	if (k == M) {
		cout << 1;
		exit(0);
	}
	else {
		A = function[k][0];
		B = function[k][1];
		if (A > 0)
			A = variable[A - 1];
		else
			A = (variable[(A * (-1) - 1)] + 1) % 2;
		if (B > 0)
			B = variable[B - 1];
		else
			B = (variable[(B * (-1) - 1)] + 1) % 2;
		if (A + B > 0)
			Judge(k + 1);
		else
			return;		
	}
}