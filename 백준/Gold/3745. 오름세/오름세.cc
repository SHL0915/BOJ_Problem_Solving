#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> N) {
		vector <int> ans;
		for (int i = 0; i < N; i++) cin >> arr[i];
		for (int i = 0; i < N; i++) {
			if (ans.size() == 0 || arr[i] > ans.back()) ans.push_back(arr[i]);
			else {
				int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
				ans[idx] = arr[i];
			}
		}
		cout << ans.size() << '\n';
	}
	return 0;
}