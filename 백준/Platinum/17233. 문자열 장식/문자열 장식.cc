#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f;

int N, L, ans = 0x3f3f3f3f;
string arr[101];
deque <pii> cnt[101];
int pi[10001];
string S;

void makePi(string s);
void kmp(string s, int idx);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		cin >> arr[i];
	}
	cin >> L >> S;
	for (int i = 0; i < N; i++) {
		makePi(arr[i]);
		kmp(S, i);
	}
	for (int i = 0; i <= L; i++) {
		int end = 0;
		for (int j = 0; j < N; j++) {
			while (cnt[j].size()) {
				if (cnt[j].front().first < i) cnt[j].pop_front();
				else break;
			}
			if (cnt[j].size() == 0) {
				end = INF;
				break;
			}
			else end = max(end, cnt[j].front().second);			
		}
		ans = min(ans, end - i);
	}
	cout << ans;
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

void makePi(string s) {
	int n = s.length(), pos = 1, k = 0;
	while (pos + k < n) {
		if (s[pos + k] == s[k]) {
			k++;
			pi[pos + k - 1] = k;
		}
		else {
			if (k == 0) pos++;
			else {
				pos += (k - pi[k - 1]);
				k = pi[k - 1];
			}
		}
	}
	return;
}

void kmp(string s, int idx) {
	int n = s.length(), m = arr[idx].length(), pos = 0, k = 0;
	while (pos + m <= n) {
		if (k < m && s[pos + k] == arr[idx][k]) {
			k++;
			if (k == m) cnt[idx].push_back({ pos, pos + m });
		}
		else {
			if (k == 0) pos++;
			else {
				pos += (k - pi[k - 1]);
				k = pi[k - 1];
			}
		}
	}
	return;
}