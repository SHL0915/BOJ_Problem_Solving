#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, ans;
int arr[11][11];

bool isValid(int col);
bool check(int col1, int col2);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) arr[i][j] = s[j] - '0';
	}
	for (int i = 1; i < 10; i++) {
		if (isValid(i) == false) continue;
		int flag = 1;
		for (int j = 1; j < 10; j++) {
			if (i == j || isValid(j) == false) continue;
			if (check(i, j) == true) flag = 0;
		}
		ans += flag;
	}
	cout << ans;
	return 0;
}

bool isValid(int col) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) if (arr[i][j] == col) return true;
	}
	return false;
}

bool check(int col1, int col2) {
	int mx = INF, my = INF, Mx = -1, My = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == col2) {
				mx = min(mx, j);
				my = min(my, i);
				Mx = max(Mx, j);
				My = max(My, i);
			}
		}
	}
	for (int i = my; i <= My; i++) {
		for (int j = mx; j <= Mx; j++) {
			if (arr[i][j] == col1) return true;
		}
	}
	return false;
}