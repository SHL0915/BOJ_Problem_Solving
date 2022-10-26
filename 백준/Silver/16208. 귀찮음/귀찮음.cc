#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long ans;
long long stick;
long long len[500000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> len[i];
		stick += len[i];
	}
	sort(len, len + N);
	for (int i = 0; i < N - 1; i++) {
		ans += len[i] * (stick - len[i]);
		stick -= len[i];
	}
	cout << ans;
	return 0;
}