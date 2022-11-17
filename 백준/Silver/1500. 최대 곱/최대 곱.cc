#include <iostream>
using namespace std;

long long S, K;
long long arr[20];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S >> K;
	for (int i = 0; i < K; i++) arr[i] = S / K;
	S %= K;
	for (int i = 0; i < K; i++) {
		if (S > 0) {
			arr[i] ++;
			S--;
		}
	}
	long long ans = 1;
	for (int i = 0; i < K; i++) ans *= arr[i];
	cout << ans;
	return 0;
}