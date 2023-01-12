#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1005];
int mark[1005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		memset(mark, 0, sizeof(mark));
		int cnt = 1;
		vector <int> ans(N + 1);
		ans[0] = i; mark[i] = 1;
		for (int j = 0; j < N - 1; j++) {
			int now = arr[j] - ans[j];
			if (mark[now] || now <= 0 || now > N) break;
			else {
				mark[now] = 1;
				ans[j + 1] = now;
				cnt++;
			}			
		}
		if (cnt == N) {
			for (int j = 0; j < N; j++) cout << ans[j] << " ";
			return 0;
		}
	}
	return 0;
}