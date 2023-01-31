#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[1000001];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	vector <int> ans;
	for (int i = 0; i < N; i++) {
		if (ans.size() == 0 || arr[i] > ans.back()) ans.push_back(arr[i]);
		else {
			int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
			ans[idx] = arr[i];			
		}
	}
	cout << ans.size();
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}