#include <iostream>
#include <algorithm>
using namespace std;

int N;
int houses[200000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> houses[i];
	sort(houses, houses + N);
	if (N % 2 == 0) cout << houses[N / 2 - 1];
	else cout << houses[N / 2];
	return 0;
}