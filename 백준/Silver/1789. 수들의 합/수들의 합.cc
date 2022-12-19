#include <bits/stdc++.h>
using namespace std;

long long S;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	long long sum = 0;
	for (int i = 1; ; i++) {
		sum += i;
		if (sum > S) {
			cout << i - 1;
			return 0;
		}
	}
	return 0;
}