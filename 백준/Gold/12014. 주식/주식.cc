#include <bits/stdc++.h>
using namespace std;

int T, N, K, tc;
int arr[10000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		tc++;
		cin >> N >> K;
		vector <int> ans;
		for (int i = 0; i < N; i++) cin >> arr[i];
		for (int i = 0; i < N; i++) {
			if (ans.size() == 0 || arr[i] > ans.back()) ans.push_back(arr[i]);
			else {
				int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
				ans[idx] = arr[i];
			}
		}
		cout << "Case #" << tc << '\n' << (ans.size() >= K) << '\n';		
	}
	return 0;
}