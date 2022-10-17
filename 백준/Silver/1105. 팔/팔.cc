#include <iostream>
using namespace std;

string L, R;
int L_num[11];
int R_num[11];
int ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> L >> R;
	int pos = 10;
	for (int i = L.size() - 1; i >= 0; i--) L_num[pos--] = L[i] - '0';
	pos = 10;
	for (int i = R.size() - 1; i >= 0; i--) R_num[pos--] = R[i] - '0';
	for (int i = 0; i < 11; i++) {
		if (L_num[i] != R_num[i]) break;
		else if (L_num[i] == 8) ans++;
	}
	cout << ans;
	return 0;
}