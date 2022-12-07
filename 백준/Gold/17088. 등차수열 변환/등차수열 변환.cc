#include <bits/stdc++.h>
using namespace std;

int N, ans = 1234567890;;
int arr[100000];
int df[9] = { 0, 0, 0, 1, 1, 1, -1, -1, -1 };
int ds[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

void BackTracking(int k, int val, int cnt);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	if (N == 1 || N == 2) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < 9; i++) {
		arr[0] += df[i];
		arr[1] += ds[i];
		int temp;
		switch (i) {
		case 0: temp = 1; break;
		case 1: temp = 0; break;
		case 2: temp = 1; break;
		case 3: temp = 2; break;
		case 4: temp = 1; break;
		case 5: temp = 2; break;
		case 6: temp = 2; break;
		case 7: temp = 1; break;
		case 8: temp = 2; break;
		}
		BackTracking(2, arr[1] - arr[0], temp);
		arr[0] -= df[i];
		arr[1] -= ds[i];
	}
	if (ans == 1234567890) cout << -1;
	else cout << ans;
	return 0;
}

void BackTracking(int k, int val, int cnt) {
	if (k == N) ans = min(ans, cnt);
	else {
		switch ((arr[k] - arr[k - 1]) - val) {
		case 0: BackTracking(k + 1, val, cnt); break;
		case 1: arr[k]--; BackTracking(k + 1, val, cnt + 1); arr[k]++; break;
		case -1: arr[k]++; BackTracking(k + 1, val, cnt + 1); arr[k]--; break;
		default: break;
		}
	}
}