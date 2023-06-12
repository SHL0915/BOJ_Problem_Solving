#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005];
string T = "TRUTH";
string F = "LIE";

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		if (s == T) arr[i] = 0;
		else arr[i] = 1;
	}

	for (int i = N - 1; i >= 1; i--) arr[i - 1] ^= arr[i];
	
	if (arr[0] == 0) cout << T;
	else cout << F;

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