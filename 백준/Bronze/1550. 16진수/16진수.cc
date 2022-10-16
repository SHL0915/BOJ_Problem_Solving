#include <iostream>
using namespace std;

int ans;

int main(void) {	
	string S;
	cin >> S;
	int temp = 1;
	for (int i = S.length() - 1; i >= 0; i--) {
		if (S[i] >= 'A' && S[i] <= 'F') ans += temp * (S[i] - 'A' + 10);
		else ans += temp * (S[i] - '0');
		temp *= 16;
	}
	cout << ans;
	return 0;
}