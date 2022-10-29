#include <iostream>
#include <cmath>
using namespace std;

long long N, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	double temp = sqrt(N);
	ans = (long long)temp;
	cout << ans;
	return 0;
}