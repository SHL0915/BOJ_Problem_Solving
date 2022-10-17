#include <iostream>;
using namespace std;

int pos;
int A_num[10001];
int B_num[10001];
int newNum[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string A, B;
	cin >> A >> B;
	pos = 10000;
	for (int i = A.length() - 1; i >= 0; i--) A_num[pos--] = A[i] - '0';
	pos = 10000;
	for (int i = B.length() - 1; i >= 0; i--) B_num[pos--] = B[i] - '0';
	for (int i = 10000; i >= 1; i--) {
		newNum[i] += (A_num[i] + B_num[i]);
		newNum[i - 1] += newNum[i] / 10;
		newNum[i] %= 10;
	}
	int flag = 0;
	for (int i = 0; i < 10001; i++) {
		if (newNum[i] != 0) flag = 1;
		if (flag == 1) cout << newNum[i];
	}
	return 0;
}