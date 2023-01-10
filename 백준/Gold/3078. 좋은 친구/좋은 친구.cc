#include <bits/stdc++.h>
using namespace std;

int N, K;
long long ans;
deque <string> dq;
int cnt[21];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (dq.size() < K + 1) {
			dq.push_back(s);
			ans += cnt[s.length()];
			cnt[s.length()]++;
		}
		else {
			cnt[dq.front().length()]--;
			dq.pop_front();
			dq.push_back(s);
			ans += cnt[s.length()];
			cnt[s.length()]++;
		}
	}
	cout << ans;
	return 0;
}