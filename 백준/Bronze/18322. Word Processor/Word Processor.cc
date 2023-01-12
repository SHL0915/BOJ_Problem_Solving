#include <bits/stdc++.h>
using namespace std;

int N, K, cnt;
string ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (cnt + s.length() <= K) {
			ans += s + " ";
			cnt += s.length();
		}
		else {
			ans.erase(ans.end() - 1);
			ans += '\n' + s + " ";
			cnt = s.length();
		}
	}
	ans.erase(ans.end() - 1);
	cout << ans;
	return 0;
}