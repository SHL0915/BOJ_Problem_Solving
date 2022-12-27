#include <bits/stdc++.h>
using namespace std;

int N, val;
int arr[100005];
int psum[100005];
long long table[100005][5];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	if (psum[N] % 4) {
		cout << 0;
		return 0;
	}
	val = psum[N] / 4;
	table[0][0] = 1;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= N; j++) table[j][i - 1] += table[j - 1][i - 1];
		for (int j = 1; j <= N; j++) {
			if (psum[j] == val * i) table[j][i] += table[j - 1][i - 1];
		}
	}
	cout << table[N][4];
	return 0;
}