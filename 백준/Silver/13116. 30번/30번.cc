#include <iostream>
using namespace std;

int T, A, B;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		while (A != B) {
			if (A > B) {
				if (A % 2 == 0) A /= 2;
				else A = (A - 1) / 2;
			}
			else {
				if (B % 2 == 0) B /= 2;
				else B = (B - 1) / 2;
			}
		}
		cout << A * 10 << '\n';
	}
	return 0;
}