#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[(1 << 25)];
int temp[(1 << 25)];
int psum[(1 << 25)];

void DnC(int left, int right);


void solve() {
	cin >> N;
	if (N == 1) {
		cout << "#";
		return;
	}
	int cnt = 1;
	while (cnt < N) cnt <<= 1;
	for (int i = 1; i <= cnt; i += 2) {
		if (N) {
			arr[i] = 1;
			N--;
		}
	}
	for (int i = 2; i <= cnt; i += 2) {
		if (N) {
			arr[i] = 1;
			N--;
		}
	}
	for (int i = 1; i <= cnt; i++) psum[i] = psum[i - 1] + arr[i];	
	DnC(1, cnt);
	for (int i = 1; i <= cnt; i++) {
		if (arr[i]) cout << "#";
		else cout << ".";
	}
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

void DnC(int left, int right) {
	int len = right - left + 1;
	if (len == 2) return;
	int mid = (left + right) / 2;
	if (psum[right] - psum[left - 1] == len / 2) {
		for (int i = left; i <= right; i++) {
			if (i <= mid) arr[i] = 1;
			else arr[i] = 0;
		}
	}
	else {		
		DnC(left, mid);
		DnC(mid + 1, right);
	}
	return;
}