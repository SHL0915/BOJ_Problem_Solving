#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, flag;
int pi[1001], revpi[1001], cmp[1001], rev[1001];
vector <int> arr[1001];

void makePi();
void kmp(int idx);

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int m; cin >> m;
		arr[i].resize(m);
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}
	for (int i = 0; i <= arr[0].size() - K; i++) {
		for (int j = 0; j < K; j++) {
			cmp[j] = arr[0][i + j];
			rev[K - j - 1] = cmp[j];
		}
		memset(pi, 0, sizeof(pi));
		memset(revpi, 0, sizeof(revpi));
		makePi();
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			flag = 0;
			kmp(j);
			cnt += flag;
		}
		if (cnt == N) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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

void makePi() {
	int n = K, pos = 1, k = 0;
	while (pos + k < n) {
		if (cmp[pos + k] == cmp[k]) {
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
	pos = 1;
	k = 0;
	while (pos + k < n) {
		if (rev[pos + k] == rev[k]) {
			k++;
			revpi[pos + k - 1] = k;
		}
		else {
			if (k == 0) pos++;
			else {
				pos += (k - revpi[k - 1]);
				k = revpi[k - 1];
			}
		}
	}
	return;
}

void kmp(int idx) {
	int n = arr[idx].size(), m = K, pos = 0, k = 0;
	while (pos + m <= n) {
		if (k < m && arr[idx][pos + k] == cmp[k]) {
			k++;
			if (k == m) flag = 1;			
		}
		else {
			if (k == 0) pos++;
			else {
				pos += (k - pi[k - 1]);
				k = pi[k - 1];
			}
		}
	}
	pos = 0;
	k = 0;
	while (pos + m <= n) {
		if (k < m && arr[idx][pos + k] == rev[k]) {
			k++;
			if (k == m) flag = 1;
		}
		else {
			if (k == 0) pos++;
			else {
				pos += (k - revpi[k - 1]);
				k = revpi[k - 1];
			}
		}
	}
	return;
}