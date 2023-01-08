#include <bits/stdc++.h>
using namespace std;

int N, ans;
pair<pair<int, int>, int> arr[101];
int shell[4];

int guess(int init);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[i] = { {a,b},c };
	}
	ans = max({ guess(1),guess(2), guess(3) });
	cout << ans;
	return 0;
}

int guess(int init) {
	memset(shell, 0, sizeof(shell));
	shell[init] = 1;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		a = arr[i].first.first;
		b = arr[i].first.second;
		c = arr[i].second;
		swap(shell[a], shell[b]);
		cnt += shell[c];
	}
	return cnt;
}