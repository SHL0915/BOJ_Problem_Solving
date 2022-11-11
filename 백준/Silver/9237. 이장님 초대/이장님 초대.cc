#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int seed[100001];

bool cmp(int A, int B) {
	return A > B;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> seed[i];
	sort(seed, seed + N, cmp);
	for (int i = 0; i < N; i++) ans = max(ans, seed[i] + i);
	cout << ans + 2;
	return 0;
}