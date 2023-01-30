#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, flag;
int arr[400001];
int cmp[200001];
int pi[200001];

void makePi();
void kmp();

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) arr[i + N] = arr[i] + 360000;
	for (int i = 0; i < 2 * N; i++) arr[i] = arr[i + 1] - arr[i];
	for (int i = 0; i < N; i++) cin >> cmp[i];
	sort(cmp, cmp + N);
	int a = cmp[0] + 360000 - cmp[N - 1];
	for (int i = 0; i < N; i++) cmp[i] = cmp[i + 1] - cmp[i];
	cmp[N - 1] = a;
	makePi();
	kmp();
	if (flag) cout << "possible";
	else cout << "impossible";
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
	int pos = 1, k = 0;
	while (pos + k < N) {
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
	return;
}

void kmp() {
	int pos = 0, k = 0;
	while (pos + N <= 2 * N) {
		if (k < N && arr[pos + k] == cmp[k]) {
			k++;
			if (k == N) flag = 1;
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