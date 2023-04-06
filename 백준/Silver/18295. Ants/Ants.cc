#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector <int> arr;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		if (s[0] == '-') continue;
		else if (s.length() > 7) continue;

		int converted = 0;
		for (int j = 0; j < s.length(); j++) {
			converted *= 10;
			converted += s[j] - '0';
		}
		arr.push_back(converted);
	}

	sort(arr.begin(), arr.end());

	int now = 0;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] != now) {
			cout << now;
			return;
		}
		else now++;
	}

	cout << now;

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}