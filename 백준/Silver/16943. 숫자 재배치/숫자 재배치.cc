#include <bits/stdc++.h>
using namespace std;

string A;
int B, ans = -1;
int bt[10];
int mark[10];

void BackTracking(int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B;
	BackTracking(0);
	cout << ans;
	return 0;
}

void BackTracking(int k) {
	if (k == A.length()) {
		if (bt[0] == 0) return;
		int result = 0;
		for (int i = 0; i < A.length(); i++) {
			result *= 10;
			result += bt[i];
		}
		if (result < B) ans = max(ans, result);
	}
	else {
		for (int i = 0; i < A.length(); i++) {
			if (mark[i] == 0) {
				bt[k] = A[i] - '0';
				mark[i] = 1;
				BackTracking(k + 1);
				mark[i] = 0;
			}
		}
	}
}