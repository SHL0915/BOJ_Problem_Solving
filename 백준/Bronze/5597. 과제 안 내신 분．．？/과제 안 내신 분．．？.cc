#include <iostream>
using namespace std;

int student[31];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 28; i++) {
		int input;
		cin >> input;
		student[input] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		if (student[i] == 0) cout << i << '\n';
	}
	return 0;
}