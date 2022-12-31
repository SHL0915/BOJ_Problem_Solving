#include <bits/stdc++.h>
using namespace std;

int N, cnt;
int arr[10][10];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) if (s[j] == '1') arr[i][j] = 1;
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			if (arr[i][j]) {
				for (int a = 0; a <= i; a++) {
					for (int b = 0; b <= j; b++) arr[a][b] ^= 1;
				}
				cnt++;
			}
		}
	}
	cout << cnt;	
	return 0;
}