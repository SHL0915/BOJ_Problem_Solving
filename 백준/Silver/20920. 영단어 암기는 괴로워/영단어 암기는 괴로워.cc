#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
map <string, int> cnt;
vector <string> arr;

bool cmp(string a, string b);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		if (s.length() < M) continue;
		if(cnt[s] == 0) arr.push_back(s);
		cnt[s]++;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < arr.size(); i++) cout << arr[i] << '\n';
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

bool cmp(string a, string b) {
	if (cnt[a] == cnt[b]) {
		if (a.length() == b.length()) return a < b;		
		return a.length() > b.length();
	}
	return cnt[a] > cnt[b];
}