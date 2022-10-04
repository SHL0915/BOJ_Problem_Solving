#include <iostream>
#include <algorithm>
using namespace std;

string A, B, C;
int memo[101][101][101];

int main(void) {
	cin >> A >> B >> C;
	for (int i = 1; i <= A.length(); i++) {
		for (int j = 1; j <= B.length(); j++) {
			for (int k = 1; k <= C.length(); k++) {
				if (B[j - 1] == A[i - 1] && A[i - 1] == C[k - 1]) memo[i][j][k] = memo[i - 1][j - 1][k - 1] + 1;
				else {
					int temp = max(memo[i][j - 1][k], memo[i - 1][j][k]);
					memo[i][j][k] = max(temp, memo[i][j][k - 1]);
				}
			}
		}
	}
	cout << memo[A.length()][B.length()][C.length()];
	return 0;
}