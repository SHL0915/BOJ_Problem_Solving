#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
int road[105];
int speed[105];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int pos = 1;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		for (int j = 0; j < A; j++) road[pos + j] = B;
		pos += A;
	}
	pos = 1;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		for (int j = 0; j < A; j++) ans = max(ans, B - road[pos + j]);
		pos += A;
	}
	cout << ans;
	return 0;
}