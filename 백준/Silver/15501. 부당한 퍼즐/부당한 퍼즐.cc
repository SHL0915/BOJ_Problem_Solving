#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[2000001];
int rev[2000001];
int cmp[2000001];

void solve() {
	cin >> N;

	int arr_idx, rev_idx;
	for (int i = 0; i < N; i++) {
		cin >> arr[i]; arr[i + N] = arr[i];
		rev[N - 1 - i] = arr[i];
		rev[2 * N - 1 - i] = arr[i];
	}

	for (int i = 0; i < N; i++) cin >> cmp[i];

	for (int i = 0; i < N; i++) {
		if (arr[i] == cmp[0]) arr_idx = i;
		if (rev[i] == cmp[0]) rev_idx = i;
	}

	int flag = 0;
	for (int i = 0; i < N; i++) {
		if (arr[arr_idx + i] != cmp[i]) flag = 1;
	}

	if (flag == 0) {
		cout << "good puzzle";
		return;
	}

	flag = 0;
	
	for (int i = 0; i < N; i++) {
		if (rev[rev_idx + i] != cmp[i]) flag = 1;
	}

	if (flag == 0) cout << "good puzzle";
	else cout << "bad puzzle";

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