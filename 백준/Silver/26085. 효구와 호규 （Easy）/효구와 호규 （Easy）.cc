#include <bits/stdc++.h>
using namespace std;

int N, M, zero_cnt, one_cnt, sum;
int arr[1000][1000];
int mask[1000][1000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) zero_cnt++;
			else one_cnt++;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i % 2 == 0 && j % 2 == 0) mask[i][j] = 1;
			else if (i % 2 == 1 && j % 2 == 1) mask[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) if (arr[i][j] == mask[i][j]) sum++;	
	}
	if (zero_cnt % 2 == 1 || one_cnt % 2 == 1 || sum == 0 || sum == N * M) cout << -1;
	else cout << 1;	
	return 0;
}