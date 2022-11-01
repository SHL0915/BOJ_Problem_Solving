#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, T, ans;
vector <long long> bus;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		long long S, I, C;
		cin >> S >> I >> C;
		for (int j = 0; j < C; j++) bus.push_back(S + I * j);
	}
	sort(bus.begin(), bus.end());
	if (T > bus.back()) cout << -1;
	else {
		ans = bus[lower_bound(bus.begin(), bus.end(), T) - bus.begin()] - T;
		cout << ans;
	}
	return 0;
}