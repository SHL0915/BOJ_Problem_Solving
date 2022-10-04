#include <iostream>
#include <algorithm>
using namespace std;

string A, B;
int memo[1001][1001];
char output[1000];

int main(void) {
	cin >> A >> B;
	for (int i = 1; i <= A.length(); i++) {
		for (int j = 1; j <= B.length(); j++) {
			if (A[i - 1] == B[j - 1]) memo[i][j] = memo[i - 1][j - 1] + 1;
			else memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
		}
	}
	cout << memo[A.length()][B.length()] << '\n';
	if (memo[A.length()][B.length()] == 0)
		return 0;
	int index = 0;
	int i = A.length(), j = B.length();
	while (1) {
		if (memo[i][j] == 0)
			break;
		if (memo[i - 1][j] == (memo[i][j] - 1) && memo[i][j - 1] == (memo[i][j] - 1)) {
			output[index++] = A[i - 1];
			i--;
			j--;
		}
		else if (memo[i - 1][j] == memo[i][j]) i--;
		else j--;
	}
	for (int i = index - 1; i >= 0; i--) 
		cout << output[i];	
	return 0;
}