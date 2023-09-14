#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 100005;

string S;
int N, M, d, sa[SZ], lcp[SZ], now[SZ], temp[SZ], cnt[SZ], se[SZ], rev[SZ], pi[SZ];
int seg[2 * SZ + 5];

void make_pi(string &s) {
	int n = s.length(), pos = 1, k = 0;
	while (pos + k < n) {
		if (s[k] == s[pos + k]) {
			k++;
			pi[pos + k - 1] = k;
		}
		else {
			if (k == 0) pos++;
			else {
				pos += k - pi[k - 1];
				k = pi[k - 1];
			}
		}
	}
	return;
}

void update(int pos, int val) {
	for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = min(seg[pos], seg[pos ^ 1]);
	return;
}

int query(int l, int r) {
	r++;
	int ret = 0x3f3f3f3f;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = min(ret, seg[l++]);
		if (r & 1) ret = min(ret, seg[--r]);
	}
	return ret;
}

int bs(int s, int val) {
	int l = s + 1, r = N - 1;
	int ans = s;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (query(s + 1, mid) < val) r = mid - 1;
		else {
			ans = mid;
			l = mid + 1;
		}
	}
	return ans;
}

void solve() {
	cin >> S;
	N = S.length();
	M = max(256, N) + 1;

	for (int i = 0; i < N; i++) sa[i] = i, now[i] = S[i];

	auto cmp = [&](int a, int b) {
		if (now[a] != now[b]) return now[a] < now[b];
		else return now[min(a + d, N)] < now[min(b + d, N)];
	};

	for (d = 1; d < N; d <<= 1) {
		fill(cnt, cnt + M, 0);
		cnt[0] = d;
		for (int i = d; i < N; i++) cnt[now[i]]++;
		for (int i = 1; i < M; i++) cnt[i] += cnt[i - 1];
		for (int i = 0; i < N; i++) se[--cnt[now[min(i + d, N)]]] = i;

		fill(cnt, cnt + M, 0);
		for (int i = 0; i < N; i++) cnt[now[i]]++;
		for (int i = 1; i < M; i++) cnt[i] += cnt[i - 1];
		for (int i = N - 1; i >= 0; i--) sa[--cnt[now[se[i]]]] = se[i];

		temp[sa[0]] = 1;
		for (int i = 1; i < N; i++) temp[sa[i]] = temp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
		for (int i = 0; i < N; i++) now[i] = temp[i];
		if (now[sa[N - 1]] == N) break;
	}

	for (int i = 0; i < N; i++) rev[sa[i]] = i;

	int l = 0;
	for (int i = 0; i < N; i++, l = max(l - 1, 0)) {
		if (rev[i] == 0) continue;
		for (int j = sa[rev[i] - 1]; S[i + l] == S[j + l]; l++);
		lcp[rev[i]] = l;
	}

	for (int i = 0; i < N; i++) update(i, lcp[i]);

	vector <int> ans;
	make_pi(S);

	int now = N;
	while (now > 0) {
		ans.push_back(now);
		now = pi[now - 1];
	}
	
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int a : ans) cout << a << " " << bs(rev[N - a], a) - rev[N - a] + 1 << '\n';	

	return;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}