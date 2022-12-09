#include <bits/stdc++.h>
using namespace std;

int arr[8], mark[8], bt[8];
int ans;

void BackTracking(int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 8; i++) cin >> arr[i];
	BackTracking(0);
	cout << ans;
	return 0;
}

void BackTracking(int k) {
	if (k == 8) {
		int temp[16];
		for (int i = 0; i < 8; i++) {
			temp[i] = arr[bt[i]];
			temp[i + 8] = arr[bt[i]];
		}
		for (int i = 0; i < 8; i++) {
			int A = temp[i];
			int B = temp[i + 2];
			double t = (A * B * sqrt(2) / (A + B));
			if (t > temp[i + 1]) return;
		}
		ans++;
		return;
	}
	else {
		for (int i = 0; i < 8; i++) {
			if (mark[i] == 0) {
				bt[k] = i;
				mark[i] = 1;
				BackTracking(k + 1);
				mark[i] = 0;
			}
		}
	}
}