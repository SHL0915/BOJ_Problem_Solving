#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pair <string, string> arr[200005];
map <string, int> m;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;	
		string code = "";
		code += arr[i].first[0]; code += arr[i].first[1];
		if (code == arr[i].second) continue;
		code += arr[i].second;
		m[code]++;
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		string a = arr[i].first, b = arr[i].second;
		string code = b;
		code += arr[i].first[0]; code += arr[i].first[1];
		cnt += m[code];
	}

	cout << cnt / 2;
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