#include <iostream>
using namespace std;

int table[100001];
int A, B, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (long long i = 2; i <= 100000; i++) {
		if (table[i] == 0) {
			table[i] = i;
			for (long long j = i * i; j <= 100000; j += i) table[j] = i;
		}
	}
	cin >> A >> B;
	for (int i = A; i <= B; i++) {
		int cnt = 0;
		int temp = i;
		while (temp != 1) {
			temp /= table[temp];
			cnt++;
		}
		if (table[cnt] == cnt) ans++;
	}
	cout << ans;
	return 0;
}