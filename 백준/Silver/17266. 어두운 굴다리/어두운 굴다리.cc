#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans;
int lamp[100000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> lamp[i];
	ans = lamp[0];
	for (int i = 1; i < M; i++) {
		int temp = (lamp[i] - lamp[i - 1]) / 2;
		if ((lamp[i] - lamp[i - 1]) % 2 == 0) ans = max(ans, temp);
		else ans = max(ans, temp + 1);
	}
	ans = max(ans, N - lamp[M - 1]);
	cout << ans;
	return 0;
}