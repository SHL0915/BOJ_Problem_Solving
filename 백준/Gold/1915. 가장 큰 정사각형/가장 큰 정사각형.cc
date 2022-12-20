#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, M, ans;
int arr[1000][1000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) arr[i][j] = s[j] - '0';
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) continue;			
			if (i == 0 || j == 0) {
				arr[i][j] = 1;
				continue;
			}
			int m = min({ arr[i][j - 1], arr[i - 1][j], arr[i - 1][j - 1] });
			arr[i][j] = m + 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) ans = max(ans, arr[i][j] * arr[i][j]);
	}
	cout << ans;
	return 0;
}