#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
int arr[15][15];

int isValid(int x, int y);
int check(int x, int y);
void reverse(int x, int y, int k);
void BackTracking(int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '#') arr[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				int temp = isValid(j, i);
				for (int k = 0; k <= temp; k++) {
					reverse(j, i, k);
					BackTracking(1 + 4 * k);
					reverse(j, i, k);
				}
			}
		}
	}
	cout << ans;
	return 0;
}

int isValid(int x, int y) {	
	for (int i = 0; ; i++) {
		int cnt = 0, x1 = x + i, y1 = y + i, x2 = x - i, y2 = y - i;
		cnt += (check(x1, y) + check(x2, y) + check(x, y1) + check(x, y2));
		if (cnt != 4) return i - 1;
	}
}

int check(int x, int y) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return 0;
	else return arr[y][x];
}

void reverse(int x, int y, int k) {
	arr[y][x] ^= 1;
	for (int i = 1; i <= k; i++) {
		arr[y - i][x] ^= 1;
		arr[y + i][x] ^= 1;
		arr[y][x - i] ^= 1;
		arr[y][x + i] ^= 1;
	}
	return;
}

void BackTracking(int k) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				int temp = isValid(j, i);
				ans = max(ans, k * (1 + 4 * temp));
			}
		}
	}
}