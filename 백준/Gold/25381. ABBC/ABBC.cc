#include <iostream>
#include <queue>
using namespace std;

string S;
int ans;
queue <int> A, B;

int main(void) {
	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'A') A.push(i);
		else if (S[i] == 'B') B.push(i);
		else {
			if (B.size() != 0) {
				B.pop();
				ans++;
			}
		}
	}
	while (1) {
		if (A.size() == 0 || B.size() == 0) break;
		if (A.front() < B.front()) {
			A.pop();
			B.pop();
			ans++;
		}
		else B.pop();
	}
	cout << ans;
	return 0;
}