#include <bits/stdc++.h>
using namespace std;

int N, ans;
vector <string> arr[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			string ss;
			cin >> ss;
			arr[i].push_back(ss);
		}
	}
	for (int i = 0; i < N; i++) {
		set <string> s;
		for (int j = 0; j < arr[i].size(); j++) s.insert(arr[i][j]);
		for (int j = i + 1; j < N; j++) {
			int cnt = 0;
			for (int k = 0; k < arr[j].size(); k++) {
				if (s.count(arr[j][k])) cnt++;
			}
			ans = max(ans, cnt + 1);
		}
	}
	cout << ans;
	return 0;
}