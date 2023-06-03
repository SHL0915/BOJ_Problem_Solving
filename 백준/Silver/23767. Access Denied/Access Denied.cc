#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string ans, in;
string access = "ACCESS GRANTED";
int N;
vector <char> arr;

void solve() {

	for (int i = 0; i < 26; i++) arr.push_back('a' + i);
	for (int i = 0; i < 26; i++) arr.push_back('A' + i);
	for (int i = 0; i < 10; i++) arr.push_back('0' + i);

	while (1) {
		ans += '0';
		cout << ans << endl;
		getline(cin, in);
		if (in == access) return;
		N = 0;
		for (int i = 15; i < in.length(); i++) {
			if (in[i] == ' ') break;
			N *= 10;
			N += in[i] - '0';
		}

		if (N != 5) break;
	}

	for (int i = 0; i < ans.size(); i++) {
		N = 5 + 9 * (i + 1);
		for (int j = 0; j < arr.size(); j++) {
			ans[i] = arr[j];
			cout << ans << endl;
			getline(cin, in);
			if (in == access) return;
			int res = 0;
			for (int k = 15; k < in.length(); k++) {
				if (in[k] == ' ') break;
				res *= 10;
				res += in[k] - '0';
			}

			if (res > N) break;
		}
	}

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}