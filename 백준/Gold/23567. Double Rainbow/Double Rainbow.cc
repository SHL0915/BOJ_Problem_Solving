#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, sz;
int tot[10005];
int arr[10005];
int cnt[10005];
set <int> s;

void push(int a);
void pop(int a);

void solve() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		tot[arr[i]]++;
	}

	for (int i = 1; i <= K; i++) {
		if (tot[i] < 2) {
			cout << 0;
			return;
		}
	}

	int ans = 0x3f3f3f3f;
	int l = 1, r = 1;

	for (; l <= N; l++) {
		if (sz == K && s.size() == 0) ans = min(ans, r - l);
		for (; r <= N; r++) {		
			if (sz == K) break;
			push(r);
			if (sz == K && s.size() == 0) ans = min(ans, r - l + 1);
		}		
		pop(l);
	}

	if (ans == 0x3f3f3f3f) cout << 0;
	else cout << ans;
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

void push(int a) {
	if (cnt[arr[a]] == 0) sz++;
	cnt[arr[a]]++;
	if (cnt[arr[a]] == tot[arr[a]]) s.insert(arr[a]);
	return;
}

void pop(int a) {
	if (cnt[arr[a]] == 1) sz--;
	if (cnt[arr[a]] == tot[arr[a]]) s.erase(arr[a]);
	cnt[arr[a]]--;
	return;
}