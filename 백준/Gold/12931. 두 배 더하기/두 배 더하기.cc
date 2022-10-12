#include <iostream>
#include <bit>
using namespace std;

int N, ans, maxNum;
int B[50];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		maxNum = max(maxNum, B[i]);
	}
	if (maxNum == 0) {
		cout << 0;
		return 0;
	}
	while (maxNum != 1) {
		maxNum /= 2;
		ans++;
	}
	for (int i = 0; i < N; i++) ans += popcount((unsigned int)B[i]);
	cout << ans;
	return 0;
}