#include <iostream>
using namespace std;

int T;
const int score[5][5] =
{ {5,-1,-2,-1,-3},
{-1,5,-3,-2,-4},
{-2,-3,5,-2,-2},
{-1,-2,-2,5,-1},
{-3,-4,-2,-1, -1000} };
long long table[201][201];
string A, B;

int CtoI(char c);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j <= 100; j++) for (int k = 0; k <= 100; k++) table[j][k] = 0;
		int Alen, Blen;
		string temp;
		cin >> Alen >> A;
		cin >> Blen >> B;
		A = " " + A;
		B = " " + B;
		for (int j = 1; j <= Alen; j++) table[j][0] = table[j - 1][0] + score[CtoI(A[j])][4];
		for (int j = 1; j <= Blen; j++) table[0][j] = table[0][j - 1] + score[4][CtoI(B[j])];
		for (int j = 1; j <= Alen; j++) {			
			for (int k = 1; k <= Blen; k++) {				
				table[j][k] = max(table[j - 1][k] + score[CtoI(A[j])][4], table[j][k - 1] + score[4][CtoI(B[k])]);
				table[j][k] = max(table[j][k], table[j - 1][k - 1] + score[CtoI(A[j])][CtoI(B[k])]);
			}
		}				
		cout << table[Alen][Blen] << '\n';
	}
	return 0;
}

int CtoI(char c) {
	switch (c) {
	case 'A': return 0;
	case 'C': return 1;
	case 'G': return 2;
	case 'T': return 3;
	default: return 4;
	}
}