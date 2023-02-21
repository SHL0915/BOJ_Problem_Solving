#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[101];

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) arr[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int temp[101];
		for (int i = a; i <= b; i++) temp[i] = arr[b - (i - a)];
		for (int i = a; i <= b; i++) arr[i] = temp[i];
	}
	for (int i = 1; i <= N; i++) cout << arr[i] << " ";
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