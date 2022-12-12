#include <bits/stdc++.h>
using namespace std;

int N, M, ans = 1234567890;
vector <int> arr[4001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		arr[A].push_back(B);
		arr[B].push_back(A);
	}
	for (int i = 1; i <= N; i++) sort(arr[i].begin(), arr[i].end());
	for (int i = 1; i <= N; i++) {
		int x = upper_bound(arr[i].begin(), arr[i].end(), i) - arr[i].begin();
		for (int j = x; j < arr[i].size(); j++) {
			int B = arr[i][j];
			int y = upper_bound(arr[B].begin(), arr[B].end(), B) - arr[B].begin();
			for (int k = y; k < arr[B].size(); k++) {
				int C = arr[B][k];
				if (binary_search(arr[i].begin(), arr[i].end(), C)) {
					ans = min(ans, (int)(arr[i].size() + arr[B].size() + arr[C].size() - 6));
				}
			}
		}
	}
	if (ans == 1234567890) cout << -1;
	else cout << ans;
	return 0;
}