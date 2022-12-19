#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
int now[1000];
int past[1000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> now[i];
	for (int i = 0; i < M; i++) cin >> past[i];
	for (int i = 0; i < max(N, M); i++) ans = max(ans, past[i] - now[i]);
	cout << ans;
	return 0;
}