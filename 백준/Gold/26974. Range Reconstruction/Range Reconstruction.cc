#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, m, M;
int arr[301][301];
int ans[301];

int absol(int A) {
	if (A < 0) return -A;
	else return A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) cin >> arr[i][j];
	}
	if (N == 1) {
		cout << 0;
		return 0;
	}	
	for (int i = 1; i < N; i++) {
		int flag = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j][i - j] == arr[j][i - j - 1]) continue;
			int m = INF, M = -INF;
			for (int k = j; k < i; k++) {
				m = min(m, ans[k]);
				M = max(M, ans[k]);
			}
			int a = m + arr[j][i - j];
			int b = M - arr[j][i - j];
			ans[i] = a;
			for (int j = 0; j < i; j++) {
				if (absol(ans[j] - a) > arr[j][i - j]) {
					ans[i] = b;
					break;
				}
			}
			if (absol(ans[i - 1] - a) != arr[i - 1][1]) ans[i] = b;
			flag = 1;
			break;
		}
		if (flag == 0) ans[i] = ans[i - 1];
	}
	for (int i = 0; i < N; i++) cout << ans[i] << ' ';
	return 0;
}