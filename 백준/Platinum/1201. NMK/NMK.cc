#include <bits/stdc++.h>
using namespace std;

int N, M, K, group_num;
deque <int> group[501];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	if (K > N - M + 1 || (N % M == 0 && K < N / M) || (N % M != 0 && K < N / M + 1)) {
		cout << -1;
		return 0;
	}
	int pos = N;
	for (int i = 1; i <= N; i++) {
		if (N - i * (M - 1) < K) break;
		for (int j = 0; j < M; j++) group[i].push_front(pos - j);
		group_num++;
		pos -= M;
	}
	for (int i = 0; i < M; i++) {
		for (int j = 1; j <= group_num; j++) cout << group[j][i] << " ";
	}
	for (int i = K - group_num; i >= 1; i--) cout << i << " ";
	for (int i = K - group_num + 1; i <= pos; i++) cout << i << " ";
	return 0;
}