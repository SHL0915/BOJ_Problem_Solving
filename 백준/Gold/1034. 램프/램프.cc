#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K, ans;
int arr[51][51];
int num[51];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int sum = 0;
		for (int j = 0; j < M; j++) {
			arr[i][j] = s[j] - '0';
			sum += arr[i][j] ^ 1;
		}
		num[i] = sum;
	}
	cin >> K;
	for (int i = 0; i < N; i++) {
		if (num[i] > K || num[i] % 2 != K % 2) continue;
		set <int> pos;
		int cnt = 0;
		for (int j = 0; j < M; j++) if (arr[i][j] == 0) pos.insert(j);
		for (int j = 0; j < N; j++) {
			int sum = 0;
			for (int k = 0; k < M; k++) {
				if (pos.count(k)) sum += arr[j][k] ^ 1;
				else sum += arr[j][k];
			}
			if (sum == M) cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}