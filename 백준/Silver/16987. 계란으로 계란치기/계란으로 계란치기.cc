#include <bits/stdc++.h>
using namespace std;

int N, ans;
int S[8];
int W[8];

void BackTracking(int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i] >> W[i];
	BackTracking(0);
	cout << ans;
	return 0;
}

void BackTracking(int k) {
	if (k == N) {
		int cnt = 0;
		for (int i = 0; i < N; i++) if (S[i] <= 0) cnt++;		
		ans = max(ans, cnt);
	}
	else {
		int flag = 0;
		if (S[k] <= 0) {
			BackTracking(k + 1);
			return;
		}
		for (int i = 0; i < N; i++) {
			if (i == k) continue;
			if (S[i] > 0) {
				flag = 1;
				S[k] -= W[i];
				S[i] -= W[k];
				BackTracking(k + 1);
				S[k] += W[i];
				S[i] += W[k];
			}
		}
		if (flag == 0) BackTracking(k + 1);
	}
}