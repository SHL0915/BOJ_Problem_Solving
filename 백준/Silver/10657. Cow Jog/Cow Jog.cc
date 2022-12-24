#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> arr[100000];
vector <int> ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		if (ans.size() == 0 || arr[i].second >= ans.back()) ans.push_back(arr[i].second);
		else {
			while (ans.size()) {
				if (ans.back() > arr[i].second) ans.pop_back();
				else break;
			}
			ans.push_back(arr[i].second);
		}
	}
	cout << ans.size();
	return 0;
}