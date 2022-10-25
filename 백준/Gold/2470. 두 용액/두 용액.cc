#include <iostream>
#include <algorithm>
using namespace std;

int N, lptr, rptr;
long long liq[100000];
pair <int, int> min_liq;
long long min_val = 2000000000;

long long absolute(long long A) {
	if (A >= 0) return A;
	else return A * -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> liq[i];
	sort(liq, liq + N);
	rptr = N - 1;
	while (lptr < rptr) {
		if (absolute(liq[lptr] + liq[rptr]) <= min_val) {
			min_liq = { lptr,rptr };
			min_val = absolute(liq[lptr] + liq[rptr]);
		}
		if (absolute(liq[lptr] + liq[rptr - 1]) <= absolute(liq[lptr + 1] + liq[rptr])) rptr--;
		else lptr++;
	}	
	cout << liq[min_liq.first] << " " << liq[min_liq.second];
	return 0;
}