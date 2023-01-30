#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string arr[20001];

bool cmp(string a, string b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N, cmp);	
	for (int i = 0; i < N; i++) {
		if (i == 0) cout << arr[i] << '\n';
		else {
			if (arr[i] == arr[i - 1]) continue;
			else cout << arr[i] << '\n';
		}
	}
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

bool cmp(string a, string b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}